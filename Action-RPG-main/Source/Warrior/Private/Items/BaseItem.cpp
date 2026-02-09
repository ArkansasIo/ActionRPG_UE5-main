// Implementation for base item (expand as needed)
#include "Items/BaseItem.h"

UBaseItem::UBaseItem()
{
    ItemName = FName("DefaultItem");
    ItemID = 0;
    Description = TEXT("A basic item.");
    Rarity = 1;
}

// Auto-write marker
