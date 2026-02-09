// Base class for all abilities (skills, spells, etc.)
#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseAbility.generated.h"

UCLASS(Blueprintable)
class WARRIOR_API UBaseAbility : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability")
    FName AbilityName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability")
    float Cooldown;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability")
    float ManaCost;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability")
    FString Description;
    UFUNCTION(BlueprintCallable, Category="Ability")
    virtual void ActivateAbility();
};
