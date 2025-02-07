// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EdGraph/EdGraphSchema.h"
#include "DialogueGraphSchema.generated.h"

USTRUCT()
struct FNodeGraphSchemaAction_CreateNode : public FEdGraphSchemaAction
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TObjectPtr<class UClass> NodeClass;

	static FName StaticGetTypeId()
	{
		static FName Type("FNodeGraphSchemaAction_CreateNode");
		return Type;
	}

	virtual FName GetTypeId() const override { return StaticGetTypeId(); }

	FNodeGraphSchemaAction_CreateNode()
		: FEdGraphSchemaAction()
		, NodeClass(nullptr)
	{
	}

	FNodeGraphSchemaAction_CreateNode(FText InNodeCategory, FText InMenuDesc, FText InToolTip, UClass* InNodeClass)
		: FEdGraphSchemaAction(MoveTemp(InNodeCategory), MoveTemp(InMenuDesc), MoveTemp(InToolTip), 0)
		, NodeClass(InNodeClass)
	{
	}

	// FEdGraphSchemaAction
	virtual UEdGraphNode* PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
};


UCLASS()
class UDialogueGraphSchema : public UEdGraphSchema
{
	GENERATED_BODY()
public:
	// EdGraphSchema
	virtual void CreateDefaultNodesForGraph(UEdGraph& Graph) const override;
	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override;

	void GetPaletteActions(FGraphActionListBuilderBase& ActionMenuBuilder) const;

};
