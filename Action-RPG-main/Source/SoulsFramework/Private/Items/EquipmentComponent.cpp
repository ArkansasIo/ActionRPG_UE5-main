#include "EquipmentComponent.h"
#include "GameFramework/Actor.h"

UEquipmentComponent::UEquipmentComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UEquipmentComponent::BeginPlay()
{
    Super::BeginPlay();
}

bool UEquipmentComponent::EquipItem(FName Slot, FName ItemId)
{
    for (FEquipmentSlot& EquipSlot : EquipmentSlots)
    {
        if (EquipSlot.SlotName == Slot)
        {
            EquipSlot.ItemId = ItemId;
            ResolveMoveset();
            return true;
        }
    }
    EquipmentSlots.Add({Slot, ItemId});
    ResolveMoveset();
    return true;
}

void UEquipmentComponent::UnequipItem(FName Slot)
{
    for (FEquipmentSlot& EquipSlot : EquipmentSlots)
    {
        if (EquipSlot.SlotName == Slot)
        {
            EquipSlot.ItemId = NAME_None;
            ResolveMoveset();
            return;
        }
    }
}

FName UEquipmentComponent::GetEquippedItem(FName Slot) const
{
    for (const FEquipmentSlot& EquipSlot : EquipmentSlots)
    {
        if (EquipSlot.SlotName == Slot)
        {
            return EquipSlot.ItemId;
        }
    }
    return NAME_None;
}

float UEquipmentComponent::GetEquipLoad() const
{
    // TODO: Calculate equip load from equipped items
    return 0.f;
}

void UEquipmentComponent::ResolveMoveset()
{
    // TODO: Update moveset based on equipped weapon/shield
}
