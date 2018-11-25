// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class UE4_PluginDemos : ModuleRules
{
	public UE4_PluginDemos(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        bEnableExceptions = true;
        bEnableUndefinedIdentifierWarnings = false;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "OpenCV", "SIMPLE", "Raymarcher" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

//         PrivateIncludePaths.AddRange(
//             new string[] {
//                 "OpenCV/Public",
// 			}
//             );
    }
}
