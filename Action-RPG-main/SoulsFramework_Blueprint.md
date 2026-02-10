# Soulslike Framework Blueprint for Unreal Engine 5

This blueprint provides a modular, production-ready architecture for action RPG/MMORPG combat in Unreal Engine 5. It is data-driven, animation-driven, prediction-friendly, and network-ready.

## Folder Structure

```
/SoulsFramework/
  Public/
    Combat/
    Targeting/
    Stats/
    Items/
    Animation/
    Save/
    AI/
  Private/
    ...
/Content/SoulsFramework/
  Data/
    DA_Weapons/
    DT_Attacks/
    DT_Stats/
    DT_Damage/
    DT_AI/
  Anim/
    Notifies/
    Montages/
  UI/
  FX/
  Blueprints/
    Characters/
    Components/
```

## Core Components

### USoulsCombatComponent
- Gate & spend stamina
- Choose attack montage
- Poise/stagger/riposte
- Key functions: `TryLightAttack()`, `TryDodge()`, `ApplyPoiseDamage()`

### UTargetingComponent
- Acquire & lock-on target
- Switch based on angle
- Provide strafe aim rotation
- Key functions: `AcquireTarget()`, `SwitchTarget(right)`, `GetTargetPoint()`

### UStatsComponent
- STR/DEX/INT/FAI/VIG
- Derived stats & regen
- Resistances
- Key functions: `SpendStamina()`, `RecoverStamina()`, `ApplyDamage()`

### UEquipmentComponent
- Equip weapon, shield, armor, talisman
- Resolve movesets from data
- Key structs: `FActionRequest`, `FDamagePacket`

## Data-Driven Design

- DA_Weapon, DT_Attack, DT_Stats, DT_Damage, DT_AI
- Animations/notifies drive combat windows
- Blueprints for characters, bonfire, HUD, lock-on UI

## Gameplay Framework Classes

- `ACombatCharacter` (base for player/enemies)
- `APlayerSoulsCharacter` (player-specific)
- `ASoulsAICharacter` (enemy pawn)
- `ASoulsPlayerController` (input/camera/UI)
- `ASoulsPlayerState` (persistent stats/resources)

## Save, AI, Data, UI

- Save: `SoulsPlayerState` syncs stats/resources
- AI: `ASoulsAICharacter` drives combat behavior
- Data: weapon specs, notifies, sockets
- UI: FX, HUD, lock-on, blueprints

## Blueprint Implementation Map

- BP_SoulsCharacterBase (inherits ACombatCharacter)
- BP_PlayerSoulsCharacter
- BP_EnemySoulsCharacterBase
- BP_BonfireCheckpoint
- WBP_HUD_Souls (HP/Stamina/LockOn)
- WBP_TargetLock
- BP_Comp_Combat
- BP_Comp_Targeting
- BP_Comp_Equipment
- BP_Comp_Stats
- ABP_SoulsHumanoid (state machine: locomotion + combat overlays)
- Montages: M_Light_1, M_Light_2, M_Heavy_1, M_Dodge, M_Parry, M_Riposte

## Minimal Vertical Slice Checklist

- Player movement + stamina drain for sprint
- Lock-on acquisition + strafe locomotion
- Light attack 3-hit combo (montage sections)
- Weapon trace in hit window
- Damage + hit reactions
- Dodge with i-frames
- Enemy AI: approach → attack → recover → reposition
- Bonfire: heal + respawn point

---

For detailed C++ headers, implementation, and Python scripts to auto-create assets, see the `/SoulsFramework` and `/Content/SoulsFramework` folders.
