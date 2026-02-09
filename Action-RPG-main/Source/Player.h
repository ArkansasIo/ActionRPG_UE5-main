#pragma once
class InputSystem;
class CharacterController;
class Character;
class AbilitySystem;
class Abilities;
class Enemy;
class Inventory;
class Equipment;
class ProgressionSystem;
class Party;
class MultiplayerSystem;
class Server;
class AISystem;
class Boss;
class World;
class EventSystem;

class Player {
public:
    void ControlInput(InputSystem& input);
};

// Auto-write marker
