// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueGraph.h"
#include "Dialogue/DialogueEditor/DialogueGraphSchema.h"

UDialogueGraph::UDialogueGraph()
{
	Schema = UDialogueGraphSchema::StaticClass();
}