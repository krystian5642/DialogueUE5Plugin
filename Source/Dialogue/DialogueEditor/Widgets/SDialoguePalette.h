#pragma once

#include "SGraphPalette.h"

class UEdGraph;

class SDialoguePalette : public SGraphPalette
{
protected:
	// SGraphPalette
	virtual void CollectAllActions(FGraphActionListBuilderBase& OutAllActions) override;
};
