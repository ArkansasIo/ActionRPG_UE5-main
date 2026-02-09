// Inventory system for holding items
#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UInventoryComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory")
    TArray<class UBaseItem*> Items;
    UFUNCTION(BlueprintCallable, Category="Inventory")
    void AddItem(UBaseItem* Item);
    UFUNCTION(BlueprintCallable, Category="Inventory")
    void RemoveItem(UBaseItem* Item);
};

// Auto-write marker
