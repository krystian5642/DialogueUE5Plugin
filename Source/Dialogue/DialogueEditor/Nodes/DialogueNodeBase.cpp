// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueNodeBase.h"
#include "DialogueGraphSchema.h"

#define LOCTEXT_NAMESPACE "DialogueNodeBase"

FLinearColor UDialogueNodeBase::GetNodeBodyTintColor() const
{
	return FLinearColor(0.f, 39.f, 194.f);
}

void UDialogueNodeBase::GetMenuEntries(struct FGraphContextMenuBuilder& ContextMenuBuilder) const
{
	TSharedPtr<FNodeGraphSchemaAction_CreateNode> CreateNodeAction = MakeShared<FNodeGraphSchemaAction_CreateNode>(GetNodeTitle(ENodeTitleType::FullTitle), GetNodeTitle(ENodeTitleType::FullTitle), GetNodeTitle(ENodeTitleType::FullTitle), GetClass());
	ContextMenuBuilder.AddAction(CreateNodeAction);
}

#undef LOCTEXT_NAMESPACE