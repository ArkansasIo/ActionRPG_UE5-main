// Achievement and progression system
#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AchievementComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UAchievementComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Achievements")
    TArray<FName> UnlockedAchievements;
    UFUNCTION(BlueprintCallable, Category="Achievements")
    void UnlockAchievement(FName AchievementID);
};
