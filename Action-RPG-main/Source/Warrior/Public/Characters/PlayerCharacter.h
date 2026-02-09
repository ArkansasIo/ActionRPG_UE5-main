// Base class for all player characters
#pragma once
#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class WARRIOR_API APlayerCharacter : public ABaseCharacter
{
    GENERATED_BODY()
public:
    APlayerCharacter();
    // Add player-specific logic here
};
