#include "UIInventoryPanel.h"

void UUIInventoryPanel::UpdateInventory(const TArray<FInventoryItem>& Items)
{
    InventoryItems = Items;
    OnInventoryUpdated();
}
