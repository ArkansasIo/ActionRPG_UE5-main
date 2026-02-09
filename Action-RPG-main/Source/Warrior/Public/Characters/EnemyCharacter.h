// Base class for all enemies and NPCs
#pragma once
#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class WARRIOR_API AEnemyCharacter : public ABaseCharacter
{
    GENERATED_BODY()
public:
    AEnemyCharacter();
    // Add enemy-specific logic here
};

// Auto-write marker
