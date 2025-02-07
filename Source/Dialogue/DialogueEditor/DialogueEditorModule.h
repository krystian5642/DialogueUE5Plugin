// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once


#include "Modules/ModuleManager.h"

class IAssetTypeActions;
class FDialogueCompilerContext;

class FDialogueEditor : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	TArray<TSharedRef<IAssetTypeActions>> RegisteredAssetTypeActions;

	static TSharedPtr<FKismetCompilerContext> GetCompilerForDialogue(UBlueprint* BP, FCompilerResultsLog& InMessageLog, const FKismetCompilerOptions& InCompileOptions);
};
