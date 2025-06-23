#include "U1StatSetDataAsset.h"

UU1StatSetDataAsset::UU1StatSetDataAsset()
{
	for (int i = 0; i < static_cast<int>(EEntityStatType::MAX); i++)
		Stats.Add(static_cast<EEntityStatType>(i), 0.f);
}

float UU1StatSetDataAsset::Get(EEntityStatType StatType)
{
	if (Stats.Contains(StatType))
		return Stats[StatType];
	else
		return -1.f;
}
