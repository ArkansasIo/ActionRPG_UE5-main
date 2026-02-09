#pragma once
#include "Blueprint/UserWidget.h"
#include "UIBasePanel.generated.h"

UCLASS()
class WARRIOR_API UUIBasePanel : public UUserWidget
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="UI")
    virtual void OpenPanel();

    UFUNCTION(BlueprintCallable, Category="UI")
    virtual void ClosePanel();

    UFUNCTION(BlueprintImplementableEvent, Category="UI")
    void OnPanelOpened();

    UFUNCTION(BlueprintImplementableEvent, Category="UI")
    void OnPanelClosed();
};
