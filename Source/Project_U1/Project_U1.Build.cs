// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Project_U1 : ModuleRules
{
	public Project_U1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput", "UMG" });
    }
}
