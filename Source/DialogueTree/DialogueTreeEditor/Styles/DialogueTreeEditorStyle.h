#pragma once

#include "Styling/SlateStyle.h"

class FDialogueTreeEditorStyle : public FSlateStyleSet
{
private:
	FDialogueTreeEditorStyle();

public:
	static void Initialize();
	static void Shutdown();

private:
	static TSharedPtr<ISlateStyle> StylePtr;
};