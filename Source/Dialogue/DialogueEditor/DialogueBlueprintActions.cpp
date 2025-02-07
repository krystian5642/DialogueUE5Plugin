#include "DialogueBlueprintActions.h"
#include "DialogueBlueprint.h"
#include "DialogueEditor.h"

#define LOCTEXT_NAMESPACE "DialogueBlueprintActions"

FText FDialogueBlueprintActions::GetName() const
{
	return LOCTEXT("DialogueBlueprintActions", "Dialogue");
}

FColor FDialogueBlueprintActions::GetTypeColor() const
{
	return FColor(34, 139, 34);
}

UClass* FDialogueBlueprintActions::GetSupportedClass() const
{
	return UDialogueBlueprint::StaticClass();
}

void FDialogueBlueprintActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for(auto* Obj : InObjects)
	{
		TSharedRef<FDialogueEditor> QuestSketchEditor = MakeShared<FDialogueEditor>();
		QuestSketchEditor->CreateGraphEditor(Cast<UDialogueBlueprint>(Obj), Mode, EditWithinLevelEditor);
	}
}

#undef LOCTEXT_NAMESPACE