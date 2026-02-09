// Game state base class
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MMORPGGameState.generated.h"

UCLASS()
class WARRIOR_API AMMORPGGameState : public AGameStateBase
{
    GENERATED_BODY()
public:
    AMMORPGGameState();
    // Add game state logic here
};
