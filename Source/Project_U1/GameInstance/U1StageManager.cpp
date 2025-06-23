#include "U1StageManager.h"
#include "U1GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Project_U1/Stage/U1StageLevel.h"
#include "Project_U1/Stage/U1StageSetAsset.h"

void UU1StageManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	StageSetAsset = Cast<UU1GameInstance>(GetGameInstance())->StageSetAsset;
	GenerateMap();
}

void UU1StageManager::GenerateMap()
{
	int mapSize = 4;

	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			int randomIndex = FMath::RandRange(0, StageSetAsset->Length()-1);
			Map[i][j] = StageSetAsset->StageInfoes[randomIndex];
		}
	}
}

void UU1StageManager::OpenStage(const FStageInfo& StageInfo, EStageClearReward StageClearReward)
{
	auto CurrentLevel = GetWorld()->GetCurrentLevel();
	UGameplayStatics::OpenLevel(GetWorld(), FName(StageInfo.StageName));
	CurrentStageLevel = CurrentLevel ? Cast<AU1StageLevel>(CurrentLevel->GetLevelScriptActor()) : nullptr;

	CurrentStageLevel->SetReward(StageClearReward);
}

EStageType UU1StageManager::SetStageType(FIntPoint Location, int MapMaxSize)
{
	if (Location.X == 0 && Location.Y == 0)
	{
		return EStageType::PLAYERSTARTING;
	}
	else if (Location.X == MapMaxSize - 1 && Location.Y == MapMaxSize - 1)
	{
		return EStageType::BOSS;
	}
	else
	{
		return EStageType::NORMAL;
	}
}
