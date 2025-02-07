
#include "SDialoguePalette.h"
#include "Dialogue/DialogueEditor/DialogueGraphSchema.h"

void SDialoguePalette::CollectAllActions(FGraphActionListBuilderBase& OutAllActions)
{
	const UDialogueGraphSchema* Schema = GetDefault<UDialogueGraphSchema>();
	FGraphActionListBuilderBase ActionMenuBuilder;
	
	Schema->GetPaletteActions(ActionMenuBuilder);
	OutAllActions.Append(ActionMenuBuilder);
}