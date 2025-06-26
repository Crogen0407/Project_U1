// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "U1GameInstance.h"
#include "U1GameResultManager.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_U1_API UU1GameResultManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FString GetCurrentTimeString();

	UFUNCTION(BlueprintCallable)
	void GetReset();
};
