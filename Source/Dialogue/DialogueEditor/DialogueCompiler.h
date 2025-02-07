// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "KismetCompiler.h"

class UDialogueBlueprint;

class FDialogueCompilerContext : public FKismetCompilerContext
{
protected:
	typedef FKismetCompilerContext Super;

public:
	FDialogueCompilerContext(UDialogueBlueprint* SourceSketch, FCompilerResultsLog& InMessageLog, const FKismetCompilerOptions& InCompilerOptions);
	virtual ~FDialogueCompilerContext();
};
