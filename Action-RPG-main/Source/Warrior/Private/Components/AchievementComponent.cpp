// Implementation for achievement system
#include "Components/AchievementComponent.h"

void UAchievementComponent::UnlockAchievement(FName AchievementID)
{
    if (!UnlockedAchievements.Contains(AchievementID))
    {
        UnlockedAchievements.Add(AchievementID);
        // Add reward logic here
    }
}
