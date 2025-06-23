#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "U1StatSetDataAsset.generated.h"

UENUM(BlueprintType)
enum class EEntityStatType : uint8
{
	MaxHealth,
	AttackPower,
	AttackDelay,
	DamageReduction,    
	MoveSpeed,
	CriticalChance,
	CriticalDamage,
	CooldownReduction,
	MAX     UMETA(Hidden)  // 이거 쓰면 Count처럼 활용 가능!
};

UCLASS()
class PROJECT_U1_API UU1StatSetDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UU1StatSetDataAsset();

	float Get(EEntityStatType StatType);
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<EEntityStatType, float> Stats;
};
