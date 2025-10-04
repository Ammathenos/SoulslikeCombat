	#pragma once
 
#include "CoreMinimal.h"
#include "CombatTypes.generated.h"
 

UENUM(BlueprintType)
enum class ECombatTypes : uint8
{
	ECT_None UMETA(DisplayName = "Unarmed"),
	ECT_LightSword UMETA(DisplayName = "LightSword equipped"),
	ECT_GreatSword UMETA(DisplayName = "GreatSword Equipped")
};