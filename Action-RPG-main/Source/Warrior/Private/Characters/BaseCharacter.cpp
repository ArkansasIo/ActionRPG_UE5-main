// Core base class for all player and NPC characters
#include "Characters/BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
    Health = 100.0f;
    Mana = 50.0f;
    Stamina = 100.0f;
}

void ABaseCharacter::TakeDamage(float Amount)
{
    Health -= Amount;
    if (Health <= 0)
    {
        Die();
    }
}

void ABaseCharacter::Die()
{
    // Handle death logic (animation, respawn, etc.)
}
