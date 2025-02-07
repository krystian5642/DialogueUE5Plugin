// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DialogueEditor : ModuleRules
{
	public DialogueEditor(ReadOnlyTargetRules Target) : base(Target)
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
            "Dialogue",
            "KismetCompiler",
            "GraphEditor"
        });
    }
}
