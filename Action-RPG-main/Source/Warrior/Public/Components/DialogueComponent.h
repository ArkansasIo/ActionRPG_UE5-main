// Base class for dialogue system
#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DialogueComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UDialogueComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dialogue")
    TArray<FString> DialogueLines;
    UFUNCTION(BlueprintCallable, Category="Dialogue")
    void StartDialogue();
};

// Auto-write marker
