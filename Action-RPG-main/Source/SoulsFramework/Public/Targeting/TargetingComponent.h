#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TargetingComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SOULSFRAMEWORK_API UTargetingComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UTargetingComponent();

    UFUNCTION(BlueprintCallable)
    bool AcquireTarget();
    UFUNCTION(BlueprintCallable)
    void ClearTarget();
    UFUNCTION(BlueprintCallable)
    bool SwitchTarget(int Direction);
    UFUNCTION(BlueprintCallable)
    FVector GetTargetPoint(FName SocketName = "head") const;

    UPROPERTY(BlueprintReadOnly)
    AActor* CurrentTarget;

protected:
    virtual void BeginPlay() override;
    bool FindBestTarget();
};
