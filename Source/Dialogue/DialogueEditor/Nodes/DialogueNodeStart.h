// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "DialogueNodeBase.h"
#include "DialogueNodeStart.generated.h"

UCLASS()
class UDialogueNodeStart : public UDialogueNodeBase
{
	GENERATED_BODY()
public:
	// UEdGraphNode
	virtual void AllocateDefaultPins() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

};
