// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "WorkflowOrientedApp/WorkflowCentricApplication.h"

class UDialogueBlueprint;

class FDialogueEditor : public FWorkflowCentricApplication
{
protected:
	typedef FWorkflowCentricApplication Super;

public:
	/** IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override ;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;

	// FAssetEditorToolkit
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;

	void CreateGraphEditor(UDialogueBlueprint* DialogueBP, EToolkitMode::Type Mode, TSharedPtr<IToolkitHost> EditWithinLevelEditor);

protected:
	TSharedRef<SDockTab> SpawnTab_Graph(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_Details(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_Palette(const FSpawnTabArgs& Args);

	TSharedRef<FTabManager::FLayout> CreateGraphEditorLayout() const;

private:
	void OnNodeSingleClicked(UObject* ClickedNode) const;

	TSharedPtr<SGraphEditor> GraphEditor;
	TSharedPtr<IDetailsView> NodeDetailsView;

	static inline uint32 GraphEditorLayoutVersion = 9; 
};
