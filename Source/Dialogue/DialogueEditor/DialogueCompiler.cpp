// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueCompiler.h"
#include "DialogueBlueprint.h"

FDialogueCompilerContext::FDialogueCompilerContext(UDialogueBlueprint* SourceSketch, FCompilerResultsLog& InMessageLog, const FKismetCompilerOptions& InCompilerOptions)
	: Super(SourceSketch, InMessageLog, InCompilerOptions)
{

}

FDialogueCompilerContext::~FDialogueCompilerContext()
{

}