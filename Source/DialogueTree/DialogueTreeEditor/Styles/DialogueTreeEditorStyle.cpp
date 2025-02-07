#include "DialogueTreeEditorStyle.h"
#include "Styling/SlateStyleRegistry.h"

TSharedPtr<ISlateStyle> FDialogueTreeEditorStyle::StylePtr;

FDialogueTreeEditorStyle::FDialogueTreeEditorStyle()
	: FSlateStyleSet("FDialogueTreeEditorStyle")
{
	Set("ClassThumbnail.DialogueTreeBlueprint", new FSlateImageBrush("DialogueTree/Resources/DialogueTree.png", FVector2D(64.0, 64.0)));
}

void FDialogueTreeEditorStyle::Initialize()
{
	check(!StylePtr.IsValid());
	
	StylePtr = MakeShareable(new FDialogueTreeEditorStyle());
	FSlateStyleRegistry::RegisterSlateStyle(*StylePtr);
}

void FDialogueTreeEditorStyle::Shutdown()
{
	check(StylePtr.IsUnique());

	FSlateStyleRegistry::UnRegisterSlateStyle(*StylePtr);
	StylePtr.Reset();
}