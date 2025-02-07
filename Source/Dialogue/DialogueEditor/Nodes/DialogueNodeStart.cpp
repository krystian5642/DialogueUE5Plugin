// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueNodeStart.h"

#define LOCTEXT_NAMESPACE "DialogueNodeStart"

void UDialogueNodeStart::AllocateDefaultPins()
{
	CreatePin(EGPD_Output, TEXT("Transition"), TEXT("Out"));
}

FText UDialogueNodeStart::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("NodeTitle", "Start");
}

#undef LOCTEXT_NAMESPACE