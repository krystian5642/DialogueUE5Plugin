// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueEditor.h"
#include "DialogueGraph.h"
#include "DialogueBlueprint.h"
#include "DialogueGraphSchema.h"
#include "Kismet2/BlueprintEditorUtils.h"

#define LOCTEXT_NAMESPACE "DialogueEditor"

namespace DialogueEditorTabs
{
	static const FName GraphTabId("GraphTab");
	static const FName NodeDetailsTabId("NodeDetailsTab");
}

FName FDialogueEditor::GetToolkitFName() const
{
	return FName("DialogueEditor");
}

FText FDialogueEditor::GetBaseToolkitName() const
{
	return LOCTEXT("DialogueEditor", "Dialogue Editor");
}

FString FDialogueEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "Dialogue ").ToString();
}

FLinearColor FDialogueEditor::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0.3f, 0.2f, 0.5f, 0.5f);
}

void FDialogueEditor::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	Super::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(DialogueEditorTabs::GraphTabId, FOnSpawnTab::CreateSP(this, &FDialogueEditor::SpawnTab_Graph))
		.SetDisplayName(LOCTEXT("GraphCanvasTab", "Dialogue Graph"));
/*		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "GraphEditor.EventGraph_16x"));*/

	InTabManager->RegisterTabSpawner(DialogueEditorTabs::NodeDetailsTabId, FOnSpawnTab::CreateSP(this, &FDialogueEditor::SpawnTab_NodeDetails))
		.SetDisplayName(LOCTEXT("NodeDetailsCanvasTab", "Node Details"));
}

void FDialogueEditor::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	Super::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterAllTabSpawners();
}

void FDialogueEditor::CreateGraphEditor(UDialogueBlueprint* DialogueBP, EToolkitMode::Type Mode, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	if(!DialogueBP->MyGraph)
	{
		DialogueBP->MyGraph = FBlueprintEditorUtils::CreateNewGraph(DialogueBP, NAME_None, UDialogueGraph::StaticClass(), UDialogueGraphSchema::StaticClass());

		const UEdGraphSchema* SchemaObj = DialogueBP->MyGraph->GetSchema();
		SchemaObj->CreateDefaultNodesForGraph(*DialogueBP->MyGraph);
	}
	
	SGraphEditor::FGraphEditorEvents GraphEvents;
	GraphEvents.OnNodeSingleClicked = SGraphEditor::FOnNodeSingleClicked::CreateSP(this, &FDialogueEditor::OnNodeSingleClicked);

	GraphEditor = SNew(SGraphEditor)
		.GraphToEdit(DialogueBP->MyGraph)
		.GraphEvents(GraphEvents);

	const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("Standalone_DialogueEditor_Layout_v5")
		->AddArea
		(
			FTabManager::NewPrimaryArea()
			->Split
			(
				FTabManager::NewSplitter()
				->SetOrientation(Orient_Horizontal)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.8f)
					->AddTab(DialogueEditorTabs::GraphTabId, ETabState::OpenedTab)
				)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.2f)
					->AddTab(DialogueEditorTabs::NodeDetailsTabId, ETabState::OpenedTab)
				)
			)
		);

	InitAssetEditor(Mode, EditWithinLevelEditor, TEXT("DialogueEditorApp"), Layout, true, true, DialogueBP);
}

TSharedRef<SDockTab> FDialogueEditor::SpawnTab_Graph(const FSpawnTabArgs& Args)
{
	return SNew(SDockTab)
	[
		GraphEditor.ToSharedRef()
	];
}

TSharedRef<SDockTab> FDialogueEditor::SpawnTab_NodeDetails(const FSpawnTabArgs& Args)
{
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");

	FDetailsViewArgs QueryDetailsViewArgs;
	QueryDetailsViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;

	NodeDetailsView = PropertyEditorModule.CreateDetailView(QueryDetailsViewArgs);

	return SNew(SDockTab)
	[
		NodeDetailsView.ToSharedRef()
	];
}

void FDialogueEditor::OnNodeSingleClicked(UObject* ClickedNode) const
{
	NodeDetailsView->SetObject(ClickedNode);
}

#undef LOCTEXT_NAMESPACE
