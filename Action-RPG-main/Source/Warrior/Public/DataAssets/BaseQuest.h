// Base class for all quests
#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseQuest.generated.h"

UCLASS(Blueprintable)
class WARRIOR_API UBaseQuest : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest")
    FName QuestName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest")
    FString Description;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest")
    bool bIsCompleted;
    UFUNCTION(BlueprintCallable, Category="Quest")
    virtual void StartQuest();
    UFUNCTION(BlueprintCallable, Category="Quest")
    virtual void CompleteQuest();
};

// Auto-write marker
