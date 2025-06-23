// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "U1GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_U1_API UU1GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<class UU1StageSetAsset> StageSetAsset;
};
