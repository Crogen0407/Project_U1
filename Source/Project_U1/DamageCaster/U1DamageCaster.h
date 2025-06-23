// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "U1DamageCaster.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UU1DamageCaster : public UInterface
{
	GENERATED_BODY()
};

UENUM(BlueprintType)
enum class EAttackType : uint8
{
	Default, 
};

USTRUCT(BlueprintType)
struct FAttackInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttackInfo)
	int Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttackInfo)
	EAttackType AttackType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttackInfo)
	FVector KnockbackVector;
	//IAttacker
};

USTRUCT(BlueprintType)
struct FHitInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttackInfo)
	AActor* HitActor;
};

class PROJECT_U1_API IU1DamageCaster
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "DamageCaster")
	TArray<FHitInfo> CastDamage(const FAttackInfo AttackInfo, bool PopupText);
};
