
#include "DialogueTreeThumbnailCustomization.h"

#define LOCTEXT_NAMESPACE "FDialogueTreeThumbnailCustomization"

TSharedRef<IDetailCustomization> FDialogueTreeThumbnailCustomization::MakeInstance()
{
	return MakeShared<FDialogueTreeThumbnailCustomization>();
}

void FDialogueTreeThumbnailCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{

}

#undef LOCTEXT_NAMESPACE
