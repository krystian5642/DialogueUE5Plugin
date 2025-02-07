// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueNodeMonologue.h"

#define LOCTEXT_NAMESPACE "DialogueNodeMonologue"

void UDialogueNodeMonologue::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, TEXT("Transition"), TEXT("In"));
	CreatePin(EGPD_Output, TEXT("Transition"), TEXT("Out"));
}

FText UDialogueNodeMonologue::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("NodeTitle", "Monologue");
}

#undef LOCTEXT_NAMESPACE