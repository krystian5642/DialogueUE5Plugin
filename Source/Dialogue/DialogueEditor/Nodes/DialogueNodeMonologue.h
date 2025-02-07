// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "DialogueNodeBase.h"
#include "DialogueNodeMonologue.generated.h"

UCLASS()
class UDialogueNodeMonologue : public UDialogueNodeBase
{
	GENERATED_BODY()
public:
	// UEdGraphNode
	virtual void AllocateDefaultPins() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

protected:
	UPROPERTY(EditDefaultsOnly)
	TArray<FText> MonologueLines;

};
