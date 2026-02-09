// Core base class for all player and NPC characters
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Abstract)
class WARRIOR_API ABaseCharacter : public ACharacter
{
    GENERATED_BODY()
public:
    ABaseCharacter();
    // Core stats
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    float Health;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    float Mana;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    float Stamina;
    // Core functions
    virtual void TakeDamage(float Amount);
    virtual void Die();
};
