#include "TargetingComponent.h"
#include "GameFramework/Actor.h"

UTargetingComponent::UTargetingComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    CurrentTarget = nullptr;
}

void UTargetingComponent::BeginPlay()
{
    Super::BeginPlay();
}

bool UTargetingComponent::AcquireTarget()
{
    return FindBestTarget();
}

void UTargetingComponent::ClearTarget()
{
    CurrentTarget = nullptr;
}

bool UTargetingComponent::SwitchTarget(int Direction)
{
    // TODO: Switch target based on relative angle
    return FindBestTarget();
}

FVector UTargetingComponent::GetTargetPoint(FName SocketName) const
{
    if (CurrentTarget)
    {
        USceneComponent* RootComp = CurrentTarget->GetRootComponent();
        if (RootComp)
        {
            return RootComp->GetSocketLocation(SocketName);
        }
        return CurrentTarget->GetActorLocation();
    }
    return FVector::ZeroVector;
}

bool UTargetingComponent::FindBestTarget()
{
    // TODO: Implement distance + screen-space + LOS selection
    // Placeholder: no target found
    CurrentTarget = nullptr;
    return false;
}
