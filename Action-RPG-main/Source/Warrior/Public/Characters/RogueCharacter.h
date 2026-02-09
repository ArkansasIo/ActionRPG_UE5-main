// Rogue subclass for player characters
#pragma once
#include "Characters/PlayerCharacter.h"
#include "RogueCharacter.generated.h"

UCLASS()
class WARRIOR_API ARogueCharacter : public APlayerCharacter
{
    GENERATED_BODY()
public:
    ARogueCharacter();
    // Rogue-specific stats
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    float Stealth;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    float CritChance;
    // Rogue abilities
    void PerformStealthAttack();
};

// Auto-write marker
