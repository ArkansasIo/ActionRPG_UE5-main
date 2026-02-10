#pragma once
#include "CoreMinimal.h"
#include "RPGStatTypes.generated.h"

// 1. Core Attributes
UENUM(BlueprintType)
enum class ECoreAttribute : uint8
{
    STR, DEX, CON, INT, WIS, VIT, SPI, LCK, WIL, CHA
};

// 2. Sub-Attributes
UENUM(BlueprintType)
enum class ESubAttribute : uint8
{
    PhysicalPower, ArmorPen, AttackSpeed, Accuracy, Evasion, WeaponHandling, CritDamage,
    SpellPower, ElementalMastery, CastSpeed, MagicPen, ManaEfficiency, Overcharge,
    MaxHP, HPRegen, ShieldStrength, DamageReduction, BlockChance, ParryChance
};

// 3. Combat Stats
UENUM(BlueprintType)
enum class ECombatStat : uint8
{
    BaseDamage, SkillDamage, CritChance, CritDamage, ComboMultiplier, BackstabMultiplier, WeakPointDamage,
    Armor, MagicResist, DamageMitigation, GuardStrength, DodgeChance, BlockValue,
    AttackSpeed, CastSpeed, CooldownReduction, GlobalCooldown, MoveSpeed, TurnPriority
};

// 4. Resources
UENUM(BlueprintType)
enum class EResourceType : uint8
{
    HP, MP, Stamina, Energy, Rage, Focus, Faith, Aether, Heat, Sanity
};

// 5. Damage Types
UENUM(BlueprintType)
enum class EDamageType : uint8
{
    Physical, Fire, Ice, Lightning, Earth, Wind, Water, Light, Dark, Arcane, Poison, Bleed, Void, Chaos, True
};

// 6. Status Effects
UENUM(BlueprintType)
enum class EStatusEffect : uint8
{
    Stun, Freeze, Root, Silence, Fear, Charm, Sleep, Knockback, Knockdown,
    Burn, Poison, Bleed, Corruption, Frostbite, Shock,
    Weakness, Frailty, Hex, Slow, Cripple, Curse
};

// 7. Buffs
UENUM(BlueprintType)
enum class EBuffType : uint8
{
    PowerSurge, Berserk, ArcaneAmplify, Precision, Shielded, Fortified, Regeneration, DamageAbsorption, Invulnerability,
    Haste, Stealth, Flight, Invisibility, TrueSight, PhaseShift
};

// 8. Enemy Rank
UENUM(BlueprintType)
enum class EEnemyRank : uint8
{
    Normal, Veteran, Elite, Champion, Boss, Mythic, Ascended
};

// 9. Enemy Role
UENUM(BlueprintType)
enum class EEnemyRole : uint8
{
    Brute, Assassin, Caster, Controller, Summoner, Support, Tank, Sniper
};

// 10. Item Type
UENUM(BlueprintType)
enum class EItemType : uint8
{
    Weapon, Armor, Trinket, Consumable, Enhancement, Quest, Cosmetic
};

// 11. Gear Slot
UENUM(BlueprintType)
enum class EGearSlot : uint8
{
    Head, Chest, Legs, Gloves, Boots, MainHand, OffHand, Ring1, Ring2, Amulet, Cloak, Belt, Trinket1, Trinket2
};

// 12. Rarity
UENUM(BlueprintType)
enum class EItemRarity : uint8
{
    Common, Uncommon, Rare, Epic, Legendary, Mythic
};

// 13. PvE/PvP Context
UENUM(BlueprintType)
enum class EGameContext : uint8
{
    PvE, PvP
};

// 14. StatBlock (for Player/Mob/Boss)
USTRUCT(BlueprintType)
struct FStatBlock
{
    GENERATED_BODY();
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<ECoreAttribute, float> CoreAttributes;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<ESubAttribute, float> SubAttributes;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<ECombatStat, float> CombatStats;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<EResourceType, float> Resources;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<EDamageType, float> Resistances;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<EStatusEffect> Immunities;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float GearScore;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EEnemyRank Rank;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EEnemyRole Role;
};

// 15. Effect (Buff/Debuff)
USTRUCT(BlueprintType)
struct FEffectDefinition
{
    GENERATED_BODY();
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EBuffType BuffType;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EStatusEffect DebuffType;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float Magnitude;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float Duration;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 MaxStacks;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bIsStacking;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bIsRefreshDuration;
};

// 16. Item Data
USTRUCT(BlueprintType)
struct FItemData
{
    GENERATED_BODY();
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FString Name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EItemType Type;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EGearSlot Slot;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EItemRarity Rarity;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 RequiredLevel;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FStatBlock PvEStats;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FStatBlock PvPStats;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FEffectDefinition> Procs;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FEffectDefinition> SetBonuses;
};

// 17. Boss Data
USTRUCT(BlueprintType)
struct FBossData
{
    GENERATED_BODY();
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FString Name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) EEnemyRank Rank;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float MaxHP;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<float> PhaseThresholds;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FString> Abilities;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<EStatusEffect> Immunities;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FEffectDefinition> Affixes;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FString LootTableId;
};

#include "RPGStatTypes.generated.h"
