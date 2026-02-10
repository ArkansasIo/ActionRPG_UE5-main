#pragma once
#include "Engine/DataTable.h"
#include "DT_Attacks.generated.h"

USTRUCT(BlueprintType)
struct FAtkDef : public FTableRowBase
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName Montage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName SectionName;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 StartupFrames;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 ActiveFrames;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 RecoveryFrames;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FName> HitWindows;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FName> CancelableInto;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FName> HyperArmorWindows;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bRootMotion;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DamageMultiplier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float PoiseDamageMultiplier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ForwardImpulse;
};
