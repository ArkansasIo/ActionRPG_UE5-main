// Implementation for base quest
#include "DataAssets/BaseQuest.h"

void UBaseQuest::StartQuest()
{
    bIsCompleted = false;
    // Add quest start logic
}

void UBaseQuest::CompleteQuest()
{
    bIsCompleted = true;
    // Add quest completion logic
}
