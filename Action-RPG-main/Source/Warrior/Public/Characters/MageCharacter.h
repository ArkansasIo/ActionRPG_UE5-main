// Mage subclass for player characters
#pragma once
#include "Characters/PlayerCharacter.h"
#include "MageCharacter.generated.h"

UCLASS()
class WARRIOR_API AMageCharacter : public APlayerCharacter
{
    GENERATED_BODY()
public:
    AMageCharacter();
    // Mage-specific stats
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    float SpellPower;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    float MagicResistance;
    // Mage abilities
    void CastSpell();
};

// Auto-write marker
