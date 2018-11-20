// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class UE4_OpenCV : ModuleRules
{
	public UE4_OpenCV(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        bEnableExceptions = true;
        bEnableUndefinedIdentifierWarnings = false;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "OpenCV" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        PrivateIncludePaths.AddRange(
            new string[] {
                "OpenCV/Public",
			}
            );
    }
}
