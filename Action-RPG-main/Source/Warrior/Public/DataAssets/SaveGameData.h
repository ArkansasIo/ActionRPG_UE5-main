// Save/Load system for player and world data
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveGameData.generated.h"

UCLASS()
class WARRIOR_API USaveGameData : public USaveGame
{
    GENERATED_BODY()
public:
    USaveGameData();
    // Add save data variables here
};
