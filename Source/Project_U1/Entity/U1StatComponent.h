// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Project_U1/Stat/U1StatSetDataAsset.h"
#include "U1StatComponent.generated.h"

USTRUCT(BlueprintType)
struct FStatModifier
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, float> Modifiers;
};


class UU1StatSetDataAsset;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_U1_API UU1StatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UU1StatComponent();

	UFUNCTION(BlueprintCallable, Category = "Stat")
	float GetOriginStatValue(EEntityStatType StatType);
	UFUNCTION(BlueprintCallable, Category = "Stat")
	int GetOriginStatIntegerValue(EEntityStatType StatType);

	UFUNCTION(BlueprintCallable, Category = "Stat")
	float GetFinalStatValue(EEntityStatType StatType);
	UFUNCTION(BlueprintCallable, Category = "Stat")
	int GetFinalStatIntegerValue(EEntityStatType StatType);

public:
	UFUNCTION(BlueprintCallable, Category = "Stat")
	void AddStatModifier(EEntityStatType StatType, float Value, int ID);
	UFUNCTION(BlueprintCallable, Category = "Stat")
	void RemoveStatModifier(EEntityStatType StatType, int ID);
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	TObjectPtr<UU1StatSetDataAsset> StatSet;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	TMap<EEntityStatType, float> OverrideStats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	TMap<EEntityStatType, FStatModifier> StatModifiers;	
};
