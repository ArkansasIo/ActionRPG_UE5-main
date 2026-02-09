// Trading and auction system
#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TradingComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UTradingComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="Trading")
    void ListItemForSale(FName ItemID, int32 Price);
    UFUNCTION(BlueprintCallable, Category="Trading")
    void BuyItem(FName ItemID);
    UFUNCTION(BlueprintCallable, Category="Trading")
    void TradeWithPlayer(FName PlayerID, FName ItemID);
    UFUNCTION(BlueprintCallable, Category="Trading")
    void SearchMarket(FString Query);
};
