// Advanced combat system
#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CombatComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UCombatComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="Combat")
    void PerformAttack(AActor* Target, FName AbilityID);
    UFUNCTION(BlueprintCallable, Category="Combat")
    void CalculateDamage(AActor* Attacker, AActor* Defender, FName AbilityID);
    UFUNCTION(BlueprintCallable, Category="Combat")
    void ApplyStatusEffect(AActor* Target, FName EffectID);
    UFUNCTION(BlueprintCallable, Category="Combat")
    void BlockAttack();
    UFUNCTION(BlueprintCallable, Category="Combat")
    void Dodge();
    UFUNCTION(BlueprintCallable, Category="Combat")
    void Parry();
    UFUNCTION(BlueprintCallable, Category="Combat")
    void HandleDeath(AActor* Target);
};
