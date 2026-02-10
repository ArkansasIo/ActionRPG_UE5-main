#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SoulsCombatTypes.h"
#include "SoulsCombatComponent.generated.h"

UENUM(BlueprintType)
enum class ECombatState : uint8
{
    Idle,
    Attacking,
    Recovering,
    Dodging,
    Blocking,
    Parrying,
    Staggered,
    Riposting,
    Dead
};

UENUM(BlueprintType)
enum class EActionPriority : uint8
{
    None,
    Light,
    Heavy,
    Skill,
    Dodge,
    Parry,
    UseItem
};

USTRUCT(BlueprintType)
struct FActionRequest
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    EActionPriority Priority;
    UPROPERTY(BlueprintReadWrite)
    FName ActionName;
    UPROPERTY(BlueprintReadWrite)
    float Timestamp;
};

USTRUCT(BlueprintType)
struct FStaggerSpec
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    float Duration;
    UPROPERTY(BlueprintReadWrite)
    float PoiseDamage;
    UPROPERTY(BlueprintReadWrite)
    FName MontageSection;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SOULSFRAMEWORK_API USoulsCombatComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USoulsCombatComponent();

    // Action API
    UFUNCTION(BlueprintCallable)
    bool TryLightAttack();
    UFUNCTION(BlueprintCallable)
    bool TryHeavyAttack();
    UFUNCTION(BlueprintCallable)
    bool TryDodge();
    UFUNCTION(BlueprintCallable)
    bool TryBlock(bool bIsBlocking);
    UFUNCTION(BlueprintCallable)
    bool TryParry();
    UFUNCTION(BlueprintCallable)
    bool CommitAction(const FActionRequest& Request);

    // Hit window
    UFUNCTION(BlueprintCallable)
    void StartHitWindow(FName WindowId);
    UFUNCTION(BlueprintCallable)
    void EndHitWindow(FName WindowId);

    // Poise
    UFUNCTION(BlueprintCallable)
    void ApplyPoiseDamage(float Amount, AActor* Source);
    UFUNCTION(BlueprintCallable)
    void EnterStagger(const FStaggerSpec& StaggerSpec);

    // State
    UPROPERTY(BlueprintReadOnly)
    ECombatState CombatState;
    UPROPERTY(BlueprintReadOnly)
    EActionPriority CurrentPriority;
    UPROPERTY(BlueprintReadOnly)
    int32 ComboIndex;
    UPROPERTY(BlueprintReadOnly)
    float LastAttackTime;
    UPROPERTY(BlueprintReadOnly)
    FActionRequest BufferedInput;

protected:
    virtual void BeginPlay() override;

    // Internal helpers
    void UpdateCombatState(ECombatState NewState);
    void ResetCombo();
};
