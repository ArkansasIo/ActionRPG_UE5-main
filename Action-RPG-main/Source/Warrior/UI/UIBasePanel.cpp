#include "UIBasePanel.h"

void UUIBasePanel::OpenPanel()
{
    SetVisibility(ESlateVisibility::Visible);
    OnPanelOpened();
}

void UUIBasePanel::ClosePanel()
{
    SetVisibility(ESlateVisibility::Collapsed);
    OnPanelClosed();
}
