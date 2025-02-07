// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "DialogueBlueprint.generated.h"

UCLASS()
class UDialogueBlueprint : public UBlueprint
{
	GENERATED_BODY()
public:
	UDialogueBlueprint();

	UPROPERTY()
	TObjectPtr<class UEdGraph> MyGraph;
};
