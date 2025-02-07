// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueEditorModule.h"
#include "DialogueBlueprintActions.h"
#include "DialogueBlueprint.h"
#include "DialogueCompiler.h"
#include "KismetCompilerModule.h"
#include "Dialogue/Dialogue/Dialogue.h"

IMPLEMENT_MODULE(FDialogueEditor, DialogueEditor)

#define LOCTEXT_NAMESPACE "FDialogueEditor"

void FDialogueEditor::StartupModule()
{
	IAssetTools& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	const TSharedRef<IAssetTypeActions> DialogueBlueprintActions = MakeShareable(new FDialogueBlueprintActions());
	RegisteredAssetTypeActions.Add(DialogueBlueprintActions);
	AssetToolsModule.RegisterAssetTypeActions(DialogueBlueprintActions);

	IKismetCompilerInterface& KismetCompilerModule = FModuleManager::LoadModuleChecked<IKismetCompilerInterface>("KismetCompiler");
	KismetCompilerModule.OverrideBPTypeForClass(UDialogue::StaticClass(), UDialogueBlueprint::StaticClass());

	FKismetCompilerContext::RegisterCompilerForBP(UDialogueBlueprint::StaticClass(), &FDialogueEditor::GetCompilerForDialogue);
}

void FDialogueEditor::ShutdownModule()
{
	if(FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
		for(const auto& AssetTypeAction : RegisteredAssetTypeActions)
		{
			AssetToolsModule.UnregisterAssetTypeActions(AssetTypeAction);
		}
	}
	RegisteredAssetTypeActions.Empty();
}

TSharedPtr<FKismetCompilerContext> FDialogueEditor::GetCompilerForDialogue(UBlueprint* BP, FCompilerResultsLog& InMessageLog, const FKismetCompilerOptions& InCompileOptions)
{
	return TSharedPtr<FDialogueCompilerContext>(new FDialogueCompilerContext(CastChecked<UDialogueBlueprint>(BP), InMessageLog, InCompileOptions));
}

#undef LOCTEXT_NAMESPACE