// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "DialogueTree.generated.h"

UCLASS(Blueprintable)
class DIALOGUETREE_API UDialogueTree : public UObject
{
	GENERATED_BODY()
public:
	UDialogueTree();

#if WITH_EDITORONLY_DATA
private:
	UPROPERTY()
	TObjectPtr<class UEdGraph> MyGraph;

#endif
};
