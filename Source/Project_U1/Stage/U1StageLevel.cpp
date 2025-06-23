#include "U1StageLevel.h"
#include "DrawDebugHelpers.h"
#include "Project_U1/Entity/U1Player.h"

AU1StageLevel::AU1StageLevel()
{
	
}

void AU1StageLevel::BeginPlay()
{
	Super::BeginPlay();
	ResetPlayerLocation();
}

void AU1StageLevel::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	
	DrawDebugPoint(GetWorld(), PlayerStartLocation, 32.f, FColor::Red, true);
}

void AU1StageLevel::ResetPlayerLocation() const
{
	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		if (AU1Player* PlayerActor = Cast<AU1Player>(PC->GetCharacter()))
		{
			PlayerActor->SetActorLocation(PlayerStartLocation);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("PlayerActor 캐스팅 실패! AU1Player 타입이 아닙니다."));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("GetFirstPlayerController()가 nullptr입니다."));
	}
}
