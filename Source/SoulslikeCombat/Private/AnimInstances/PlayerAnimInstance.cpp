// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/PlayerAnimInstance.h"
#include "SoulslikeCombat/DebugMacros.h"

void UPlayerAnimInstance::UpdateCombatType(ECombatTypes CombatType)
{
	CombatTypeLocal = CombatType;
}

void UPlayerAnimInstance::UpdateWeaponAttachedToHand(bool AttachedToHand)
{
	AttachedToHandLocal = AttachedToHand;
}
