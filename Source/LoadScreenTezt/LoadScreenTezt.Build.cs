// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LoadScreenTezt : ModuleRules
{
	public LoadScreenTezt(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "MoviePlayer" });
		
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
	}
}
