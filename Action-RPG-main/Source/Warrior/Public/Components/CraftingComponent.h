// Crafting and gathering system
#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CraftingComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UCraftingComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="Crafting")
    void GatherResource(FName ResourceType);
    UFUNCTION(BlueprintCallable, Category="Crafting")
    void CraftItem(FName RecipeID);
    UFUNCTION(BlueprintCallable, Category="Crafting")
    void LearnRecipe(FName RecipeID);
    UFUNCTION(BlueprintCallable, Category="Crafting")
    void UpgradeItem(FName ItemID);
};
