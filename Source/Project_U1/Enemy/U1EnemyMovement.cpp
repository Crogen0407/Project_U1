#include "U1EnemyMovement.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Navigation/PathFollowingComponent.h"
#include "Project_U1/Entity/U1StatComponent.h"

UU1EnemyMovement::UU1EnemyMovement()
{
	bOrientRotationToMovement = false;
	bUseControllerDesiredRotation = true;
}

void UU1EnemyMovement::Initialize(UU1StatComponent* StatComponent)
{
	CashedStatComponent = StatComponent;
	
	MaxWalkSpeed = CashedStatComponent->GetFinalStatValue(EEntityStatType::MoveSpeed);
	
	OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn)
	{
		AIController = Cast<AAIController>(OwnerPawn->GetController());
	}
	
	TargetActor = Cast<AActor>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void UU1EnemyMovement::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!TargetActor || !AIController)
		return;

	float Distance = FVector::Dist(OwnerPawn->GetActorLocation(), TargetActor->GetActorLocation());

	if (Distance > DashableDistance)
	{
		OnDash(); // 거리 넘어가면 대시 실행
	}
	if (AIController)
	{
		// 간단하게 NavMesh를 통해 추적
		FAIMoveRequest MoveReq;
		MoveReq.SetGoalActor(TargetActor);
		MoveReq.SetAcceptanceRadius(200.f); // 도착 판정 거리

		FNavPathSharedPtr NavPath;
		AIController->MoveTo(MoveReq, &NavPath);
	}

	FVector ToTarget = TargetActor->GetActorLocation() - GetPawnOwner()->GetActorLocation();
	FRotator DesiredRot = ToTarget.Rotation();
	FRotator CurrentRot = GetPawnOwner()->GetActorRotation();
	FRotator NewRot = FMath::RInterpTo(CurrentRot, DesiredRot, DeltaTime, 5.0f);
	GetPawnOwner()->SetActorRotation(NewRot);
}
