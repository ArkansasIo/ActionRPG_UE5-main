#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EquipmentComponent.generated.h"

USTRUCT(BlueprintType)
struct FEquipmentSlot
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite)
    FName SlotName;
    UPROPERTY(BlueprintReadWrite)
    FName ItemId;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SOULSFRAMEWORK_API UEquipmentComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UEquipmentComponent();

    UFUNCTION(BlueprintCallable)
    bool EquipItem(FName Slot, FName ItemId);
    UFUNCTION(BlueprintCallable)
    void UnequipItem(FName Slot);
    UFUNCTION(BlueprintCallable)
    FName GetEquippedItem(FName Slot) const;
    UFUNCTION(BlueprintCallable)
    float GetEquipLoad() const;

    UPROPERTY(BlueprintReadOnly)
    TArray<FEquipmentSlot> EquipmentSlots;

protected:
    virtual void BeginPlay() override;
    void ResolveMoveset();
};
