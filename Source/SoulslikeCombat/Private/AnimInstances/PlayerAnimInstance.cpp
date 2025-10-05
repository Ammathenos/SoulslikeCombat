// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/PlayerAnimInstance.h"
#include "SoulslikeCombat/DebugMacros.h"
#include "SoulslikeCombat/DebugMacros.h"

void UPlayerAnimInstance::UpdateCombatType(ECombatTypes CombatType)
{
	CombatTypeLocal = CombatType;
}

void UPlayerAnimInstance::UpdateCombatEnabled(bool CombatEnabled)
{
	CombatEnabledLocal = CombatEnabled;
}