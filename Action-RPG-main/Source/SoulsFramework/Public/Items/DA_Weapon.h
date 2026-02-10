#pragma once
#include "Engine/DataAsset.h"
#include "DA_Weapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
    StraightSword,
    Greatsword,
    Spear,
    Katana,
    Axe,
    Hammer,
    Staff,
    Bow
};

USTRUCT(BlueprintType)
struct FWeaponScaling
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite)
    float STR;
    UPROPERTY(BlueprintReadWrite)
    float DEX;
    UPROPERTY(BlueprintReadWrite)
    float INT;
    UPROPERTY(BlueprintReadWrite)
    float FAI;
    UPROPERTY(BlueprintReadWrite)
    float ARC;
};

UCLASS(BlueprintType)
class SOULSFRAMEWORK_API UDA_Weapon : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    EWeaponType WeaponType;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DamageBasePhysical;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DamageBaseMagic;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DamageBaseFire;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DamageBaseHoly;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FWeaponScaling Scaling;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float PoiseDamage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StaminaCostLight;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StaminaCostHeavy;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StaminaCostSkill;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName MovesetId;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName TraceProfile;
};
