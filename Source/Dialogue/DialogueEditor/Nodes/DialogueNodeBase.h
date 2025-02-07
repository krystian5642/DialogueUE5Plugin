// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EdGraph/EdGraphNode.h"
#include "DialogueNodeBase.generated.h"

UCLASS()
class UDialogueNodeBase : public UEdGraphNode
{
	GENERATED_BODY()
public:
	// UEdGraphNode
	virtual FLinearColor GetNodeBodyTintColor() const override;
	virtual void GetMenuEntries(struct FGraphContextMenuBuilder& ContextMenuBuilder) const override;

};
