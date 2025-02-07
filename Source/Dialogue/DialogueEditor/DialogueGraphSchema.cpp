// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueGraphSchema.h"
#include "Nodes/DialogueNodeStart.h"

#define LOCTEXT_NAMESPACE "DialogueGraphSchema"

UEdGraphNode* FNodeGraphSchemaAction_CreateNode::PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode)
{
	UDialogueNodeBase* NewGraphNode = NewObject<UDialogueNodeBase>(ParentGraph, NodeClass, NAME_None, RF_Transactional);
	NewGraphNode->CreateNewGuid();
	NewGraphNode->AllocateDefaultPins();

	NewGraphNode->NodePosX = Location.X;
	NewGraphNode->NodePosY = Location.Y;

	ParentGraph->AddNode(NewGraphNode, true, bSelectNewNode);

	return NewGraphNode;
}

void UDialogueGraphSchema::CreateDefaultNodesForGraph(UEdGraph& Graph) const
{
	UDialogueNodeBase* StartGraphNode = NewObject<UDialogueNodeBase>(&Graph, UDialogueNodeStart::StaticClass(), NAME_None, RF_Transactional);
	StartGraphNode->CreateNewGuid();
	StartGraphNode->AllocateDefaultPins();
	StartGraphNode->NodePosX = 0;
	StartGraphNode->NodePosY = 50;

	Graph.AddNode(StartGraphNode, false, true);

	SetNodeMetaData(StartGraphNode, "StartDialogueNode");
}

const FPinConnectionResponse UDialogueGraphSchema::CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const
{
	if(A->GetOwningNode() == B->GetOwningNode())
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, LOCTEXT("ConnectionSameNode", "Both are on the same node"));
	}

	const UEdGraphPin* InputPin = nullptr;
	const UEdGraphPin* OutputPin = nullptr;

	if(!CategorizePinsByDirection(A, B, InputPin, OutputPin))
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, LOCTEXT("ConnectionIncompatible", "Directions are not compatible"));
	}

	return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, TEXT(""));
}

void UDialogueGraphSchema::GetPaletteActions(FGraphActionListBuilderBase& ActionMenuBuilder) const
{

}

#undef  LOCTEXT_NAMESPACE
