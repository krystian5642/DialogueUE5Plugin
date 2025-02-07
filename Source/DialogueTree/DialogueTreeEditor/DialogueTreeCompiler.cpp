// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueTreeCompiler.h"
#include "DialogueTreeBlueprint.h"

FDialogueTreeCompilerContext::FDialogueTreeCompilerContext(UDialogueTreeBlueprint* SourceSketch, FCompilerResultsLog& InMessageLog, const FKismetCompilerOptions& InCompilerOptions)
	: Super(SourceSketch, InMessageLog, InCompilerOptions)
{

}

FDialogueTreeCompilerContext::~FDialogueTreeCompilerContext()
{

}