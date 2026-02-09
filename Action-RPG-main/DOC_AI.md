# AI System

## Overview
Controls enemy, NPC, and boss behaviors, including movement, targeting, and decision-making.

## Key Functions
- SetTarget(AActor* Target)
- Patrol()
- EngageCombat()
- Flee()
- UseAbility(UBaseAbility* Ability)
- HandleDeath()
- Boss phase logic

## AI Types
- Passive NPC
- Aggressive Mob
- Boss (multi-phase)
- Ally/Companion

---
*See BaseAIController.h/cpp for code structure. Expand with new AI behaviors and blackboard/behavior tree logic as needed.*

// Auto-write marker
