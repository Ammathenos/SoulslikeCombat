// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseWeapon.h"
#include "SoulslikeCombat/SoulslikeCombatCharacter.h"
#include "SoulslikeCombat/DebugMacros.h"
#include "AnimInstances/PlayerAnimInstance.h"
#include "Animation/AnimMontage.h"

void ABaseWeapon::OnEquipped(ASoulslikeCombatCharacter* PlayerCharacter)
{
	//Super::OnEquipped(PlayerCharacter);

	FName SocketName;
	SetIsEquipped(true);

	if (PlayerCharacter)
	{
		switch (PlayerCharacter->IsCombatEnabled())
		{
		case false:
			SocketName = AttachSocketName;
			break;

		case true:
			SocketName = HandSocketName;
			break;
		}

		AttachActor(SocketName, PlayerCharacter);
		PlayerCharacter->SetNewMainWeapon(this);
		UPlayerAnimInstance* PlayerAnimInstanceVar = Cast<UPlayerAnimInstance>(PlayerCharacter->GetMesh()->GetAnimInstance());

		if (PlayerAnimInstanceVar)
		{
			PlayerAnimInstanceVar->UpdateCombatType(CombatType);
			//DEBUG_PRINT2(CombatType);
		}
	}
}
