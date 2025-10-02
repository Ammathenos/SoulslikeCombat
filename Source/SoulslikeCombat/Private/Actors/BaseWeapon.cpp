// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseWeapon.h"
#include "SoulslikeCombat/SoulslikeCombatCharacter.h"
#include "SoulslikeCombat/DebugMacros.h"

void ABaseWeapon::OnEquipped(ASoulslikeCombatCharacter* PlayerCharacter)
{
	Super::OnEquipped(PlayerCharacter);

	if (PlayerCharacter)
	{
		PlayerCharacter->SetMainWeapon(this);
	}
}