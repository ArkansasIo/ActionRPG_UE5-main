#pragma once
#include "UObject/NoExportTypes.h"
#include "UIManager.generated.h"

UENUM(BlueprintType)
enum class EGameUIPanel : uint8
{
    Character,
    Inventory,
    Map,
    Talents,
    Chat,
    Quests,
    Settings,
    SkillBar,
    // Add more as needed
};

UCLASS(Blueprintable)
class WARRIOR_API UUIManager : public UObject
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="UI")
    void ShowPanel(EGameUIPanel PanelType);

    UFUNCTION(BlueprintCallable, Category="UI")
    void HidePanel(EGameUIPanel PanelType);

    UFUNCTION(BlueprintCallable, Category="UI")
    UUserWidget* GetPanel(EGameUIPanel PanelType);

protected:
    UPROPERTY()
    TMap<EGameUIPanel, UUserWidget*> PanelInstances;
};
