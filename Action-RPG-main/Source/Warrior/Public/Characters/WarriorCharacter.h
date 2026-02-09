// Warrior subclass for player characters
#pragma once
#include "Characters/PlayerCharacter.h"
#include "WarriorCharacter.generated.h"

UCLASS()
class WARRIOR_API AWarriorCharacter : public APlayerCharacter
{
    GENERATED_BODY()
public:
    AWarriorCharacter();
    // Warrior-specific stats
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    float Armor;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    float Strength;
    // Warrior abilities
    void PerformPowerAttack();
};
