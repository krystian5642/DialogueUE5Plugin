// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "KismetCompiler.h"

class UDialogueTreeBlueprint;

class FDialogueTreeCompilerContext : public FKismetCompilerContext
{
protected:
	typedef FKismetCompilerContext Super;

public:
	FDialogueTreeCompilerContext(UDialogueTreeBlueprint* SourceSketch, FCompilerResultsLog& InMessageLog, const FKismetCompilerOptions& InCompilerOptions);
	virtual ~FDialogueTreeCompilerContext();
};
