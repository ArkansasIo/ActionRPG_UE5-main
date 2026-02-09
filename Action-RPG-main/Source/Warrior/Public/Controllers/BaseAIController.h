// Base class for all AI controllers
#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAIController.generated.h"

UCLASS()
class WARRIOR_API ABaseAIController : public AAIController
{
    GENERATED_BODY()
public:
    ABaseAIController();
    // Add AI logic here
};
