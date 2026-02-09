// Base class for all equipment (weapons, armor, accessories)
#pragma once
#include "CoreMinimal.h"
#include "Items/BaseItem.h"
#include "EquipmentItem.generated.h"

UCLASS(Blueprintable)
class WARRIOR_API UEquipmentItem : public UBaseItem
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Equipment")
    int32 Attack;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Equipment")
    int32 Defense;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Equipment")
    int32 MagicPower;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Equipment")
    int32 Rarity;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Equipment")
    FString SlotType;
};
