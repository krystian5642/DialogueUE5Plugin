// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueTreeEditorModule.h"
#include "DialogueTreeBlueprintActions.h"
#include "DialogueTreeBlueprint.h"
#include "DialogueTreeCompiler.h"
#include "KismetCompilerModule.h"
#include "DialogueTree/DialogueTree/DialogueTree.h"
#include "Customizations/DialogueTreeThumbnailCustomization.h"
#include "Styles/DialogueTreeEditorStyle.h"

IMPLEMENT_MODULE(FDialogueTreeEditor, DialogueTreeEditor)

#define LOCTEXT_NAMESPACE "FDialogueTreeEditor"

void FDialogueTreeEditor::StartupModule()
{
	FDialogueTreeEditorStyle::Initialize();

	FPropertyEditorModule& PropertyEditor = FModuleManager::GetModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
	PropertyEditor.RegisterCustomClassLayout(TEXT("DialogueTreeBlueprint"), FOnGetDetailCustomizationInstance::CreateStatic(&FDialogueTreeThumbnailCustomization::MakeInstance));

	IAssetTools& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	const TSharedRef<IAssetTypeActions> DialogueTreeBlueprintActions = MakeShareable(new FDialogueTreeBlueprintActions());
	RegisteredAssetTypeActions.Add(DialogueTreeBlueprintActions);
	AssetToolsModule.RegisterAssetTypeActions(DialogueTreeBlueprintActions);

	IKismetCompilerInterface& KismetCompilerModule = FModuleManager::LoadModuleChecked<IKismetCompilerInterface>("KismetCompiler");
	KismetCompilerModule.OverrideBPTypeForClass(UDialogueTree::StaticClass(), UDialogueTreeBlueprint::StaticClass());

	FKismetCompilerContext::RegisterCompilerForBP(UDialogueTreeBlueprint::StaticClass(), &FDialogueTreeEditor::GetCompilerForDialogueTree);
}

void FDialogueTreeEditor::ShutdownModule()
{
	FDialogueTreeEditorStyle::Shutdown();

	FPropertyEditorModule* PropertyModule = FModuleManager::GetModulePtr<FPropertyEditorModule>("PropertyEditor");
	if(PropertyModule)
	{
		PropertyModule->UnregisterCustomClassLayout(TEXT("DialogueTree"));
	}

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

TSharedPtr<FKismetCompilerContext> FDialogueTreeEditor::GetCompilerForDialogueTree(UBlueprint* BP, FCompilerResultsLog& InMessageLog, const FKismetCompilerOptions& InCompileOptions)
{
	return TSharedPtr<FDialogueTreeCompilerContext>(new FDialogueTreeCompilerContext(CastChecked<UDialogueTreeBlueprint>(BP), InMessageLog, InCompileOptions));
}

#undef LOCTEXT_NAMESPACE