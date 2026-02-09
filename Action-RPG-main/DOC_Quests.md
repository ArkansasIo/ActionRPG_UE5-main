# Quest System

## Overview
Manages all quests, objectives, and quest progression for players.

## Key Functions
- StartQuest(UBaseQuest* Quest)
- CompleteQuest(UBaseQuest* Quest)
- UpdateObjective(QuestID, ObjectiveID, Progress)
- CheckQuestStatus(QuestID)
- GiveReward(QuestID)

## Quest Types
- Main Story Quests
- Side Quests
- Repeatable Quests
- World Events

---
*See BaseQuest.h/cpp for code structure. Expand with new quest types and branching logic as needed.*
