#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "Project_U1/GameInstance/U1StageManager.h"
#include "U1StageLevel.generated.h"

UCLASS()
class PROJECT_U1_API AU1StageLevel : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	AU1StageLevel();

protected:
	virtual void BeginPlay() override;

public:
	virtual void OnConstruction(const FTransform& Transform) override;
	void SetReward(const EStageClearReward StageClearReward)
	{
		this->CurrentStageClearReward = StageClearReward;
	}
	
protected:
	void ResetPlayerLocation() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PlayerStartLocation;

	EStageClearReward CurrentStageClearReward;
};
