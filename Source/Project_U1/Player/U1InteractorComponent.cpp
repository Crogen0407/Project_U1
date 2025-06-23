#include "U1InteractorComponent.h"
#include "Project_U1/Object/U1InteractableObject.h"

UU1InteractorComponent::UU1InteractorComponent()
{
	USphereComponent::SetEnableGravity(false);
	USphereComponent::SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	USphereComponent::SetCollisionObjectType(ECC_GameTraceChannel2); // 자신은 Player 채널
	USphereComponent::SetCollisionResponseToAllChannels(ECR_Ignore); // 기본적으로 모두 무시
	USphereComponent::SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Overlap); // InteractableObject만 허용

	SetShouldUpdatePhysicsVolume(true);
	SetCanEverAffectNavigation(false);
	bDynamicObstacle = true;
	
	OnComponentBeginOverlap.AddDynamic(this, &UU1InteractorComponent::OnOverlapBegin);
	OnComponentEndOverlap.AddDynamic(this, &UU1InteractorComponent::OnOverlapEnd);
}

void UU1InteractorComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (CurrentInterableObject != nullptr) return;

	CurrentInterableObject = Cast<AU1InteractableObject>(OtherActor);
	
	if (CurrentInterableObject == nullptr) return;
	CurrentInterableObject->OnSelected(true);
}

void UU1InteractorComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (CurrentInterableObject == nullptr) return;
	if (CurrentInterableObject != Cast<AU1InteractableObject>(OtherActor)) return;
	CurrentInterableObject->OnSelected(false);
	CurrentInterableObject = nullptr;
}

void UU1InteractorComponent::Interact(AU1Player* Player)
{
	if (CurrentInterableObject == nullptr) return;
	CurrentInterableObject->Interact(Player);
}

void UU1InteractorComponent::BeginPlay()
{
	Super::BeginPlay();
	
}
