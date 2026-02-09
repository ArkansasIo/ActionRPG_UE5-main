// Player state base class
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MMORPGPlayerState.generated.h"

UCLASS()
class WARRIOR_API AMMORPGPlayerState : public APlayerState
{
    GENERATED_BODY()
public:
    AMMORPGPlayerState();
    // Add player state logic here
};

// Auto-write marker
