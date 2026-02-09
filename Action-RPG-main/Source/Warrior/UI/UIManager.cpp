#include "UIManager.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "UIBasePanel.h"

void UUIManager::ShowPanel(EGameUIPanel PanelType)
{
    if (!PanelInstances.Contains(PanelType) || !PanelInstances[PanelType])
    {
        // You would load the widget class here, e.g. from a Blueprint
        // For demo, we just skip instantiation
        return;
    }
    PanelInstances[PanelType]->SetVisibility(ESlateVisibility::Visible);
    if (UUIBasePanel* Panel = Cast<UUIBasePanel>(PanelInstances[PanelType]))
    {
        Panel->OnPanelOpened();
    }
}

void UUIManager::HidePanel(EGameUIPanel PanelType)
{
    if (PanelInstances.Contains(PanelType) && PanelInstances[PanelType])
    {
        PanelInstances[PanelType]->SetVisibility(ESlateVisibility::Collapsed);
        if (UUIBasePanel* Panel = Cast<UUIBasePanel>(PanelInstances[PanelType]))
        {
            Panel->OnPanelClosed();
        }
    }
}

UUserWidget* UUIManager::GetPanel(EGameUIPanel PanelType)
{
    if (PanelInstances.Contains(PanelType))
    {
        return PanelInstances[PanelType];
    }
    return nullptr;
}
