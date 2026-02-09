// Base class for player controller
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

UCLASS()
class WARRIOR_API ABasePlayerController : public APlayerController
{
    GENERATED_BODY()
public:
    ABasePlayerController();
    // Add player input and logic here
};
