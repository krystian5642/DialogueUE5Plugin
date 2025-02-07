// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DialogueTreeEditor : ModuleRules
{
	public DialogueTreeEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicIncludePaths.Add(ModuleDirectory);

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",         
            "Slate",
            "SlateCore",
            "UnrealEd",
            "AssetTools",
            "DialogueTree",
            "KismetCompiler"
        });
    }
}
