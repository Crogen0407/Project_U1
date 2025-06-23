#include "U1StatComponent.h"
#include "MathUtil.h"

// Sets default values for this component's properties
UU1StatComponent::UU1StatComponent()
{
	if (!HasAnyFlags(RF_ClassDefaultObject)) // CDO일 경우에는 설정하지 않음
	{
		ConstructorHelpers::FObjectFinder<UU1StatSetDataAsset> DataAssetFinder(TEXT("/Game/DataAssets/DA_DefaultStatSet"));
		if (DataAssetFinder.Succeeded())
		{
			StatSet = DataAssetFinder.Object;
		}	
	}
	
	PrimaryComponentTick.bCanEverTick = false;
}

float UU1StatComponent::GetOriginStatValue(EEntityStatType StatType)
{
	if (StatSet == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("UU1StatComponent::GetOriginStatValue - StatSet이 nullptr입니다! StatSet이 제대로 세팅되었는지 확인하세요."));
		return -1.f;  // 혹은 기본값, 에러처리 값 반환
	}

	if (OverrideStats.Contains(StatType))
		return OverrideStats[StatType];
    
	return StatSet->Get(StatType);
}

int UU1StatComponent::GetOriginStatIntegerValue(EEntityStatType StatType)
{
	return static_cast<int>(FMathf::Round(GetOriginStatValue(StatType)));
}

float UU1StatComponent::GetFinalStatValue(EEntityStatType StatType)
{
	float Result = GetOriginStatValue(StatType);

	if (StatModifiers.Contains(StatType) == true)
	{
		for (auto ModifierPair : StatModifiers[StatType].Modifiers)
			Result += ModifierPair.Value;
	}

	return Result;
}

int UU1StatComponent::GetFinalStatIntegerValue(EEntityStatType StatType)
{
	return static_cast<int>(FMathf::Round(GetFinalStatValue(StatType)));
}

void UU1StatComponent::AddStatModifier(EEntityStatType StatType, float Value, int ID)
{
	if (StatModifiers.Contains(StatType) == false)
		StatModifiers.Add(StatType);

	StatModifiers[StatType].Modifiers.Add(ID, Value);
}

void UU1StatComponent::RemoveStatModifier(EEntityStatType StatType, int ID)
{
	if (StatModifiers.Contains(StatType) == true)
		StatModifiers[StatType].Modifiers.Remove(ID);
}
