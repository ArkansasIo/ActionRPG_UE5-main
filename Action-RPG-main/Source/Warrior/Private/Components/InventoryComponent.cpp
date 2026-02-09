// Implementation for inventory system
#include "Components/InventoryComponent.h"
#include "Items/BaseItem.h"

void UInventoryComponent::AddItem(UBaseItem* Item)
{
    if (Item)
    {
        Items.Add(Item);
    }
}

void UInventoryComponent::RemoveItem(UBaseItem* Item)
{
    if (Item)
    {
        Items.Remove(Item);
    }
}

// Auto-write marker
