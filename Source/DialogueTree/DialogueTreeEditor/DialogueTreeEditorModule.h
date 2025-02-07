// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once


#include "Modules/ModuleManager.h"

class IAssetTypeActions;
class FDialogueTreeCompilerContext;

class FDialogueTreeEditor : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	TArray<TSharedRef<IAssetTypeActions>> RegisteredAssetTypeActions;

	static TSharedPtr<FKismetCompilerContext> GetCompilerForDialogueTree(UBlueprint* BP, FCompilerResultsLog& InMessageLog, const FKismetCompilerOptions& InCompileOptions);
};
