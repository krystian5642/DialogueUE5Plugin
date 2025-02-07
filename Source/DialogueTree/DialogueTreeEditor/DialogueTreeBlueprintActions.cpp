#include "DialogueTreeBlueprintActions.h"
#include "DialogueTreeBlueprint.h"
#include "DialogueTreeEditor.h"

#define LOCTEXT_NAMESPACE "DialogueTreeBlueprintActions"

FText FDialogueTreeBlueprintActions::GetName() const
{
	return LOCTEXT("DialogueTreeBlueprintActions", "Dialogue Tree");
}

FColor FDialogueTreeBlueprintActions::GetTypeColor() const
{
	return FColor(34, 139, 34);
}

UClass* FDialogueTreeBlueprintActions::GetSupportedClass() const
{
	return UDialogueTreeBlueprint::StaticClass();
}

void FDialogueTreeBlueprintActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;


	for(auto* Obj : InObjects)
	{
		TSharedRef<FDialogueTreeEditor> QuestSketchEditor = MakeShared<FDialogueTreeEditor>();

		const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("Standalone_DialogueTreeEditor_Layout_v1")
			-> AddArea
			(
				FTabManager::NewPrimaryArea()->SetOrientation(Orient_Horizontal)
			);

		QuestSketchEditor->InitAssetEditor(Mode, EditWithinLevelEditor, TEXT("DialogueTreeEditorApp"), Layout, true, true, Cast<UDialogueTreeBlueprint>(Obj));
	}

}

#undef LOCTEXT_NAMESPACE