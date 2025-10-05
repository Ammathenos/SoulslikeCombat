// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseWeapon.h"
#include "SoulslikeCombat/SoulslikeCombatCharacter.h"
#include "SoulslikeCombat/DebugMacros.h"
#include "AnimInstances/PlayerAnimInstance.h"
#include "Components/CombatComponent.h"
#include "Animation/AnimMontage.h"

void ABaseWeapon::OnEquipped(ASoulslikeCombatCharacter* PlayerCharacter)
{
	if (!PlayerCharacter) return;

	Super::OnEquipped(PlayerCharacter);

	PlayerCombatComponent = PlayerCharacter->GetCombatComponent();

	if (PlayerCombatComponent)
	{
		FName SocketName = PlayerCombatComponent->IsCombatEnabled() ? HandSocketName : AttachSocketName;
		AttachActor(SocketName, PlayerCharacter);
		PlayerCombatComponent->SetMainWeapon(this);

		if (UPlayerAnimInstance* PlayerAnimInstanceVar = Cast<UPlayerAnimInstance>(PlayerCharacter->GetMesh()->GetAnimInstance()))
		{
			PlayerAnimInstanceVar->UpdateCombatType(CombatType);
		}
	}
}
