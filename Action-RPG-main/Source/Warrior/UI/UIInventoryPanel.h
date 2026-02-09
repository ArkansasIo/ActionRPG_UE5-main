#pragma once
#include "UIBasePanel.h"
#include "UIInventoryPanel.generated.h"

USTRUCT(BlueprintType)
struct FInventoryItem
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory")
    FName ItemID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory")
    int32 Quantity;
};

UCLASS()
class WARRIOR_API UUIInventoryPanel : public UUIBasePanel
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="Inventory")
    void UpdateInventory(const TArray<FInventoryItem>& Items);

    UFUNCTION(BlueprintImplementableEvent, Category="Inventory")
    void OnInventoryUpdated();

protected:
    UPROPERTY(BlueprintReadOnly, Category="Inventory")
    TArray<FInventoryItem> InventoryItems;
};
