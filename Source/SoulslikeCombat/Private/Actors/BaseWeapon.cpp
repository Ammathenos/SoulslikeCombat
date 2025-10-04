// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseWeapon.h"
#include "SoulslikeCombat/SoulslikeCombatCharacter.h"
#include "SoulslikeCombat/DebugMacros.h"
#include "AnimInstances/PlayerAnimInstance.h"
#include "Animation/AnimMontage.h"

void ABaseWeapon::OnEquipped(ASoulslikeCombatCharacter* PlayerCharacter)
{
	Super::OnEquipped(PlayerCharacter);

	if (PlayerCharacter)
	{
		PlayerCharacter->SetMainWeapon(this);
		UPlayerAnimInstance* PlayerAnimInstanceVar = Cast<UPlayerAnimInstance>(PlayerCharacter->GetMesh()->GetAnimInstance());

		if (PlayerAnimInstanceVar)
		{
			PlayerAnimInstanceVar->UpdateCombatType(CombatType);
		}

	}
}

void ABaseWeapon::SetAttachedToHand(bool IsAttachedToHandLocal)
{
	bIsAttachedToHand = IsAttachedToHandLocal;

	ASoulslikeCombatCharacter* PlayerCharacter = Cast<ASoulslikeCombatCharacter>(GetOwner());

	if (PlayerCharacter)
	{
		UPlayerAnimInstance* PlayerAnimInstance;
		PlayerAnimInstance = Cast<UPlayerAnimInstance>(PlayerCharacter->GetMesh()->GetAnimInstance());

		if (PlayerAnimInstance)
		{
			PlayerAnimInstance->UpdateWeaponAttachedToHand(bIsAttachedToHand);
		}
	}
}
