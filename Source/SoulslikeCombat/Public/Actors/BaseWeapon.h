// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseEquippable.h"
#include "BaseWeapon.generated.h"

/**
 * 
 */
UCLASS()
class SOULSLIKECOMBAT_API ABaseWeapon : public ABaseEquippable
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = "Initialization")
		FName HandSocketName = "None";

	FORCEINLINE FName ReturnHandSocketName() { return HandSocketName; }

	UPROPERTY(VisibleAnywhere)
		bool bIsAttachedToHand = false;
	
};
