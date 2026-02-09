// Party, guild, and social system
#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SocialComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API USocialComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="Social")
    void CreateParty();
    UFUNCTION(BlueprintCallable, Category="Social")
    void InviteToParty(FName PlayerID);
    UFUNCTION(BlueprintCallable, Category="Social")
    void LeaveParty();
    UFUNCTION(BlueprintCallable, Category="Social")
    void CreateGuild(FName GuildName);
    UFUNCTION(BlueprintCallable, Category="Social")
    void InviteToGuild(FName PlayerID);
    UFUNCTION(BlueprintCallable, Category="Social")
    void SendFriendRequest(FName PlayerID);
    UFUNCTION(BlueprintCallable, Category="Social")
    void Chat(FString Message, FString Channel);
};
