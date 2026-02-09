// Base class for all usable items (weapons, armor, consumables)
#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseItem.generated.h"

UCLASS(Blueprintable)
class WARRIOR_API UBaseItem : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
    FName ItemName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
    int32 ItemID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
    FString Description;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
    int32 Rarity;
};

// Auto-write marker
