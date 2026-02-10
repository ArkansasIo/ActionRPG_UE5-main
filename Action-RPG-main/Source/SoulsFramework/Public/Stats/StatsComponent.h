#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatsComponent.generated.h"

UENUM(BlueprintType)
enum class EAttributeType : uint8
{
    STR,
    DEX,
    INT,
    FAI,
    END,
    VIG,
    ARC
};

USTRUCT(BlueprintType)
struct FAttribute
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite)
    EAttributeType Type;
    UPROPERTY(BlueprintReadWrite)
    float Value;
};

USTRUCT(BlueprintType)
struct FDamagePacket
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite)
    AActor* Source;
    UPROPERTY(BlueprintReadWrite)
    AActor* Instigator;
    UPROPERTY(BlueprintReadWrite)
    FName WeaponId;
    UPROPERTY(BlueprintReadWrite)
    float PhysicalDamage;
    UPROPERTY(BlueprintReadWrite)
    float MagicDamage;
    UPROPERTY(BlueprintReadWrite)
    float FireDamage;
    UPROPERTY(BlueprintReadWrite)
    float HolyDamage;
    UPROPERTY(BlueprintReadWrite)
    float PoiseDamage;
    UPROPERTY(BlueprintReadWrite)
    FName HitReactionType;
    UPROPERTY(BlueprintReadWrite)
    FVector HitLocation;
    UPROPERTY(BlueprintReadWrite)
    FVector HitNormal;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SOULSFRAMEWORK_API UStatsComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UStatsComponent();

    // Core stat functions
    UFUNCTION(BlueprintCallable)
    bool SpendStamina(float Cost);
    UFUNCTION(BlueprintCallable)
    void RecoverStamina(float DeltaTime);
    UFUNCTION(BlueprintCallable)
    void ApplyDamage(const FDamagePacket& Damage);
    UFUNCTION(BlueprintCallable)
    float ComputeAttackPower(FName WeaponSpec, FName DamageType);

    // Advanced RPG/MMORPG functions
    UFUNCTION(BlueprintCallable)
    float GetAttributeValue(EAttributeType Type) const;
    UFUNCTION(BlueprintCallable)
    void AddExperience(int32 Amount);
    UFUNCTION(BlueprintCallable)
    void LevelUp();
    UFUNCTION(BlueprintCallable)
    void ApplyBuff(FName BuffId, float Duration);
    UFUNCTION(BlueprintCallable)
    void RemoveBuff(FName BuffId);
    UFUNCTION(BlueprintCallable)
    bool IsDead() const;
    UFUNCTION(BlueprintCallable)
    void Respawn(FVector Location);
    UFUNCTION(BlueprintCallable)
    bool CheckSkillRequirement(FName SkillId) const;
    UFUNCTION(BlueprintCallable)
    void ApplyItemModifier(FName ItemId);
    UFUNCTION(BlueprintCallable)
    void RemoveItemModifier(FName ItemId);

    // Stat properties
    UPROPERTY(BlueprintReadOnly)
    TArray<FAttribute> Attributes;
    UPROPERTY(BlueprintReadOnly)
    float HP;
    UPROPERTY(BlueprintReadOnly)
    float MaxHP;
    UPROPERTY(BlueprintReadOnly)
    float Stamina;
    UPROPERTY(BlueprintReadOnly)
    float MaxStamina;
    UPROPERTY(BlueprintReadOnly)
    float EquipLoad;
    UPROPERTY(BlueprintReadOnly)
    float Poise;
    UPROPERTY(BlueprintReadOnly)
    float MaxPoise;
    UPROPERTY(BlueprintReadOnly)
    float PhysicalResist;
    UPROPERTY(BlueprintReadOnly)
    float MagicResist;
    UPROPERTY(BlueprintReadOnly)
    float FireResist;
    UPROPERTY(BlueprintReadOnly)
    float HolyResist;
    UPROPERTY(BlueprintReadOnly)
    int32 Level;
    UPROPERTY(BlueprintReadOnly)
    int32 Experience;
    UPROPERTY(BlueprintReadOnly)
    int32 ExperienceToNextLevel;
    UPROPERTY(BlueprintReadOnly)
    bool bIsDead;

    // Buffs, item modifiers
    UPROPERTY(BlueprintReadOnly)
    TMap<FName, float> ActiveBuffs;
    UPROPERTY(BlueprintReadOnly)
    TArray<FName> ActiveItemModifiers;

protected:
    virtual void BeginPlay() override;
    void RegenerateStats(float DeltaTime);
    void UpdateResistances();
    void HandleDeath();
    void HandleRespawn(FVector Location);
};
