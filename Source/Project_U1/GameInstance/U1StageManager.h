#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "U1StageManager.generated.h"

#define GetStageManager GetGameInstance()->GetSubsystem<UU1StageManager>()

class AU1StageLevel;
class UU1StageSetAsset;

UENUM(BlueprintType)
enum class EStageType : uint8
{
	NONE, PLAYERSTARTING, NORMAL, BOSS
};

UENUM(BlueprintType)
enum class EStageClearReward : uint8
{
	NONE, SKILL, GOLD
};

USTRUCT(BlueprintType)
struct FStageInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString StageName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EStageType StageType;
};

UCLASS()
class PROJECT_U1_API UU1StageManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(Transient)
	TObjectPtr<UU1StageSetAsset> StageSetAsset;
	FStageInfo Map[4][4];
	AU1StageLevel* CurrentStageLevel;
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	const AU1StageLevel* GetCurrentStageLevel() const
	{
		return CurrentStageLevel;	
	}

public:
	void OpenStage(const FStageInfo& StageInfo, EStageClearReward StageClearReward);
	
private:
	void GenerateMap();
	EStageType SetStageType(FIntPoint Location, int MapMaxSize);
	
};
