// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueTreeGraph.h"
#include "DialogueTree/DialogueTreeEditor/DialogueTreeGraphSchema.h"

UDialogueTreeGraph::UDialogueTreeGraph()
{
	Schema = UDialogueTreeGraphSchema::StaticClass();
}