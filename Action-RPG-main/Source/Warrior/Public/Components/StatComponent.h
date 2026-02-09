// Stat system for characters and items
#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StatComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UStatComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    int32 Strength;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    int32 Dexterity;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    int32 Intelligence;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    int32 Vitality;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    int32 Endurance;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    int32 Luck;
};
