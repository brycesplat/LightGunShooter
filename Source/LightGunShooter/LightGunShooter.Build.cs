// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LightGunShooter : ModuleRules
{
	public LightGunShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
