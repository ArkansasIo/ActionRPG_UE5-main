#include "StatsComponent.h"
#include "GameFramework/Actor.h"

UStatsComponent::UStatsComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    MaxHP = 100.f;
    HP = MaxHP;
    MaxStamina = 100.f;
    Stamina = MaxStamina;
    MaxPoise = 50.f;
    Poise = MaxPoise;
    PhysicalResist = 0.f;
    MagicResist = 0.f;
    FireResist = 0.f;
    HolyResist = 0.f;
    EquipLoad = 0.f;
    Level = 1;
    Experience = 0;
    ExperienceToNextLevel = 100;
    bIsDead = false;
}

void UStatsComponent::BeginPlay()
{
    Super::BeginPlay();
    UpdateResistances();
}

bool UStatsComponent::SpendStamina(float Cost)
{
    if (Stamina >= Cost && !bIsDead)
    {
        Stamina -= Cost;
        return true;
    }
    return false;
}

void UStatsComponent::RecoverStamina(float DeltaTime)
{
    RegenerateStats(DeltaTime);
}

void UStatsComponent::ApplyDamage(const FDamagePacket& Damage)
{
    if (bIsDead) return;
    float totalDamage = Damage.PhysicalDamage * (1.f - PhysicalResist)
        + Damage.MagicDamage * (1.f - MagicResist)
        + Damage.FireDamage * (1.f - FireResist)
        + Damage.HolyDamage * (1.f - HolyResist);
    HP -= totalDamage;
    Poise -= Damage.PoiseDamage;
    if (HP <= 0.f)
    {
        HP = 0.f;
        HandleDeath();
    }
}

float UStatsComponent::ComputeAttackPower(FName WeaponSpec, FName DamageType)
{
    // Example: STR scaling for physical, INT for magic, etc.
    float basePower = 10.f;
    float scale = 1.f;
    if (DamageType == "Physical")
        scale = GetAttributeValue(EAttributeType::STR) * 0.1f;
    else if (DamageType == "Magic")
        scale = GetAttributeValue(EAttributeType::INT) * 0.1f;
    else if (DamageType == "Fire")
        scale = GetAttributeValue(EAttributeType::FAI) * 0.1f;
    else if (DamageType == "Holy")
        scale = GetAttributeValue(EAttributeType::ARC) * 0.1f;
    return basePower * scale;

// --- Advanced RPG/MMORPG logic ---
float UStatsComponent::GetAttributeValue(EAttributeType Type) const
{
    for (const FAttribute& Attr : Attributes)
    {
        if (Attr.Type == Type)
            return Attr.Value;
    }
    return 0.f;
}

void UStatsComponent::AddExperience(int32 Amount)
{
    if (bIsDead) return;
    Experience += Amount;
    while (Experience >= ExperienceToNextLevel)
    {
        Experience -= ExperienceToNextLevel;
        LevelUp();
    }
}

void UStatsComponent::LevelUp()
{
    Level++;
    ExperienceToNextLevel = FMath::FloorToInt(ExperienceToNextLevel * 1.2f);
    MaxHP += 10.f;
    MaxStamina += 5.f;
    HP = MaxHP;
    Stamina = MaxStamina;
    MaxPoise += 2.f;
    Poise = MaxPoise;
    // Optionally grant attribute points
}

void UStatsComponent::ApplyBuff(FName BuffId, float Duration)
{
    ActiveBuffs.Add(BuffId, Duration);
    // Example: Buff logic (increase stats, resistances, etc.)
}

void UStatsComponent::RemoveBuff(FName BuffId)
{
    ActiveBuffs.Remove(BuffId);
}

bool UStatsComponent::IsDead() const
{
    return bIsDead;
}

void UStatsComponent::Respawn(FVector Location)
{
    HandleRespawn(Location);
}

bool UStatsComponent::CheckSkillRequirement(FName SkillId) const
{
    // Example: Check if attributes meet skill requirements
    // TODO: Lookup skill requirements
    return true;
}

void UStatsComponent::ApplyItemModifier(FName ItemId)
{
    ActiveItemModifiers.Add(ItemId);
    // TODO: Apply item stat changes
}

void UStatsComponent::RemoveItemModifier(FName ItemId)
{
    ActiveItemModifiers.Remove(ItemId);
    // TODO: Remove item stat changes
}

void UStatsComponent::RegenerateStats(float DeltaTime)
{
    if (bIsDead) return;
    // HP regen (if allowed)
    HP += DeltaTime * 1.f;
    HP = FMath::Clamp(HP, 0.f, MaxHP);
    // Stamina regen
    Stamina += DeltaTime * 10.f;
    Stamina = FMath::Clamp(Stamina, 0.f, MaxStamina);
    // Poise regen
    Poise += DeltaTime * 2.f;
    Poise = FMath::Clamp(Poise, 0.f, MaxPoise);
    // Buff timers
    TArray<FName> RemoveBuffs;
    for (auto& Elem : ActiveBuffs)
    {
        Elem.Value -= DeltaTime;
        if (Elem.Value <= 0.f)
            RemoveBuffs.Add(Elem.Key);
    }
    for (const FName& BuffId : RemoveBuffs)
        RemoveBuff(BuffId);
}

void UStatsComponent::UpdateResistances()
{
    // TODO: Calculate resistances from gear, buffs, etc.
}

void UStatsComponent::HandleDeath()
{
    bIsDead = true;
    // TODO: Death logic (disable input, trigger respawn, etc.)
}

void UStatsComponent::HandleRespawn(FVector Location)
{
    bIsDead = false;
    HP = MaxHP;
    Stamina = MaxStamina;
    Poise = MaxPoise;
    // TODO: Move actor to respawn location
}
}
