#include "SoulsCombatComponent.h"
#include "GameFramework/Actor.h"

USoulsCombatComponent::USoulsCombatComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    CombatState = ECombatState::Idle;
    CurrentPriority = EActionPriority::None;
    ComboIndex = 0;
    LastAttackTime = 0.f;
}

void USoulsCombatComponent::BeginPlay()
{
    Super::BeginPlay();
    ResetCombo();
}

bool USoulsCombatComponent::TryLightAttack()
{
    // Check stamina, state, etc.
    return CommitAction(FActionRequest{EActionPriority::Light, FName("LightAttack"), GetWorld()->GetTimeSeconds()});
}

bool USoulsCombatComponent::TryHeavyAttack()
{
    return CommitAction(FActionRequest{EActionPriority::Heavy, FName("HeavyAttack"), GetWorld()->GetTimeSeconds()});
}

bool USoulsCombatComponent::TryDodge()
{
    return CommitAction(FActionRequest{EActionPriority::Dodge, FName("Dodge"), GetWorld()->GetTimeSeconds()});
}

bool USoulsCombatComponent::TryBlock(bool bIsBlocking)
{
    return CommitAction(FActionRequest{EActionPriority::Block, FName(bIsBlocking ? "BlockStart" : "BlockEnd"), GetWorld()->GetTimeSeconds()});
}

bool USoulsCombatComponent::TryParry()
{
    return CommitAction(FActionRequest{EActionPriority::Parry, FName("Parry"), GetWorld()->GetTimeSeconds()});
}

bool USoulsCombatComponent::CommitAction(const FActionRequest& Request)
{
    // TODO: Validate action, update state, spend stamina, trigger montage
    BufferedInput = Request;
    return true;
}

void USoulsCombatComponent::StartHitWindow(FName WindowId)
{
    // TODO: Enable hit tracing
}

void USoulsCombatComponent::EndHitWindow(FName WindowId)
{
    // TODO: Disable hit tracing
}

void USoulsCombatComponent::ApplyPoiseDamage(float Amount, AActor* Source)
{
    // TODO: Process poise damage, check for stagger
}

void USoulsCombatComponent::EnterStagger(const FStaggerSpec& StaggerSpec)
{
    UpdateCombatState(ECombatState::Staggered);
    // TODO: Play stagger montage, apply effects
}

void USoulsCombatComponent::UpdateCombatState(ECombatState NewState)
{
    CombatState = NewState;
}

void USoulsCombatComponent::ResetCombo()
{
    ComboIndex = 0;
    LastAttackTime = 0.f;
}
