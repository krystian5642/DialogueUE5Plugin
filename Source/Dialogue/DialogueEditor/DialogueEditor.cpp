// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueEditor.h"
#include "DialogueGraph.h"
#include "DialogueBlueprint.h"
#include "DialogueGraphSchema.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Widgets/SDialoguePalette.h"

#define LOCTEXT_NAMESPACE "DialogueEditor"

namespace DialogueEditorTabs
{
	static const FName GraphTabId("GraphTab");
	static const FName DetailsTabId("DetailsTab");
	static const FName PaletteTabId("PaletteTab");
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
		.SetDisplayName(LOCTEXT("GraphCanvasTab", "Graph"));

	InTabManager->RegisterTabSpawner(DialogueEditorTabs::DetailsTabId, FOnSpawnTab::CreateSP(this, &FDialogueEditor::SpawnTab_Details))
		.SetDisplayName(LOCTEXT("DetailsCanvasTab", "Details"));

	InTabManager->RegisterTabSpawner(DialogueEditorTabs::PaletteTabId, FOnSpawnTab::CreateSP(this, &FDialogueEditor::SpawnTab_Palette))
		.SetDisplayName(LOCTEXT("PaletteCanvasTab", "Palette"));
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

	InitAssetEditor(Mode, EditWithinLevelEditor, TEXT("DialogueEditorApp"), CreateGraphEditorLayout(), true, true, DialogueBP);
}

TSharedRef<SDockTab> FDialogueEditor::SpawnTab_Graph(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == DialogueEditorTabs::GraphTabId);

	return SNew(SDockTab)
	[
		GraphEditor.ToSharedRef()
	];
}

TSharedRef<SDockTab> FDialogueEditor::SpawnTab_Details(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == DialogueEditorTabs::DetailsTabId);

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");

	FDetailsViewArgs QueryDetailsViewArgs;
	QueryDetailsViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;

	NodeDetailsView = PropertyEditorModule.CreateDetailView(QueryDetailsViewArgs);

	return SNew(SDockTab)
	[
		NodeDetailsView.ToSharedRef()
	];
}

TSharedRef<SDockTab> FDialogueEditor::SpawnTab_Palette(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == DialogueEditorTabs::PaletteTabId);

	TSharedRef<SDialoguePalette> DialoguePalette = SNew(SDialoguePalette);

	return SNew(SDockTab)
	[
		DialoguePalette
	];
}

TSharedRef<FTabManager::FLayout> FDialogueEditor::CreateGraphEditorLayout() const
{
	return FTabManager::NewLayout(*FString::Printf(TEXT("Standalone_DialogueEditor_Layout_v%d"), GraphEditorLayoutVersion))
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
					->SetSizeCoefficient(0.20f)
					->SetHideTabWell(true)
					->AddTab(DialogueEditorTabs::DetailsTabId, ETabState::OpenedTab)
				)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.65f)
					->SetHideTabWell(true)
					->AddTab(DialogueEditorTabs::GraphTabId, ETabState::OpenedTab)
				)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.15f)
					->SetHideTabWell(true)
					->AddTab(DialogueEditorTabs::PaletteTabId, ETabState::OpenedTab)
				)
			)
		);
}

void FDialogueEditor::OnNodeSingleClicked(UObject* ClickedNode) const
{
	NodeDetailsView->SetObject(ClickedNode);
}

#undef LOCTEXT_NAMESPACE
