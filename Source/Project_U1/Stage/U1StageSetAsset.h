// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Project_U1/GameInstance/U1StageManager.h"
#include "U1StageSetAsset.generated.h"

UCLASS()
class PROJECT_U1_API UU1StageSetAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FStageInfo> StageInfoes;

	uint32 Length() const
	{
		return StageInfoes.Max();
	}
};

