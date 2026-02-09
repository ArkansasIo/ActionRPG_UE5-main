# How to Add New Content Files

## 1. Bosses, Enemies, NPCs
- Create a new file in `CONTENT_BOSSES_NPCS/` for each boss, enemy, or NPC.
- Use the following template:

```
# [Name]
- **Type:** (Boss/Enemy/NPC/World Boss/etc)
- **Rank:** (Common/Rare/Epic/Legendary/Mythic)
- **Title:** (e.g., The Ashen Dragon)
- **Zone:** (e.g., Frostspire Depths)
- **Abilities:**
  - [Ability 1]: [Description]
  - [Ability 2]: [Description]
- **Stats:**
  - HP: 
  - Attack: 
  - Defense: 
  - Special: 
- **Lore:**
  - [Short lore or background]
```

## 2. Weapons, Armor, Items
- Create a new file in `CONTENT_ITEMS_EQUIPMENT/` for each item or set.
- Use the template in `ITEM_STAT_TEMPLATE.md`.

## 3. Expanding the World
- Add new dungeons, raids, trials, and towers to `CONTENT_BOSSES_NPCS.md`.
- Add new item types, resources, and materials to `CONTENT_ITEMS_EQUIPMENT.md`.

## 4. Blueprint Integration
- After creating a C++ class, right-click in Unreal Editor → Create Blueprint Class Based on ...
- Name the Blueprint after the boss, item, or equipment for easy reference.

---
*Organize content by folders and templates for scalable development and easy documentation.*
