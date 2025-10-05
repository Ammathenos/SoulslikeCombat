// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Interfaces/AnimationInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SOULSLIKECOMBAT_API UPlayerAnimInstance : public UAnimInstance, public IAnimationInstance
{
	GENERATED_BODY()

public:
	virtual void UpdateCombatType(ECombatTypes CombatType) override;

	virtual void UpdateCombatEnabled(bool CombatEnabled) override;

	UPROPERTY(BlueprintReadOnly)
		ECombatTypes CombatTypeLocal = ECombatTypes::ECT_None;

	UPROPERTY(BlueprintReadOnly)
		bool CombatEnabledLocal;
};
