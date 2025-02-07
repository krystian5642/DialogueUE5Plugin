// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueTreeEditor.h"

#define LOCTEXT_NAMESPACE "DialogueTreeEditor"

FName FDialogueTreeEditor::GetToolkitFName() const
{
	return FName("DialogueTreeEditor");
}

FText FDialogueTreeEditor::GetBaseToolkitName() const
{
	return LOCTEXT("DialogueTreeEditor", "Dialogue Tree Editor");
}

FString FDialogueTreeEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "DialogueTree ").ToString();
}

FLinearColor FDialogueTreeEditor::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0.3f, 0.2f, 0.5f, 0.5f);
}

#undef LOCTEXT_NAMESPACE
