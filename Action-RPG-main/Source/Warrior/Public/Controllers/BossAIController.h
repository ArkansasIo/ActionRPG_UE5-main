// Advanced boss and enemy AI system
#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "BossAIController.generated.h"

UCLASS()
class WARRIOR_API ABossAIController : public AAIController
{
    GENERATED_BODY()
public:
    ABossAIController();
    UFUNCTION(BlueprintCallable, Category="BossAI")
    void StartBossPhase(int32 Phase);
    UFUNCTION(BlueprintCallable, Category="BossAI")
    void UseBossAbility(FName AbilityID);
    UFUNCTION(BlueprintCallable, Category="BossAI")
    void HandleAggro(AActor* Target);
};

// Auto-write marker
