#include "U1StatComponent.h"
#include "MathUtil.h"

// Sets default values for this component's properties
UU1StatComponent::UU1StatComponent()
{
	if (!HasAnyFlags(RF_ClassDefaultObject)) // CDO일 경우에는 설정하지 않음
	{
		ConstructorHelpers::FObjectFinder<UU1StatSetDataAsset> DataAssetFinder(TEXT("/Script/Project_U1.U1StatSetDataAsset'/Game/DataAssets/DA_DefaultStatSet.DA_DefaultStatSet'"));
		if (DataAssetFinder.Succeeded())
		{
			StatSet = DataAssetFinder.Object;
		}	
	}
	
	PrimaryComponentTick.bCanEverTick = false;
}

float UU1StatComponent::GetOriginStatValue(EEntityStatType StatType)
{
	if (OverrideStats.Contains(StatType))
		return OverrideStats[StatType];
	
	if (StatSet != nullptr)
		return StatSet->Get(StatType);

	return -1.f;
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
