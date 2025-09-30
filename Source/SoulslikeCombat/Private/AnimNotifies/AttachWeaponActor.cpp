// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifies/AttachWeaponActor.h"
#include "SoulslikeCombat/SoulslikeCombatCharacter.h"
#include "Actors/BaseWeapon.h"

void UAttachWeaponActor::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	ASoulslikeCombatCharacter* PlayerCharacter;

	PlayerCharacter = Cast<ASoulslikeCombatCharacter>(MeshComp->GetOwner());
	
	if (PlayerCharacter)
	{
		ABaseWeapon* MainWeapon;
		MainWeapon = PlayerCharacter->ReturnMainWeapon();
		
		switch (AttachToHand)
		{
		case false:
			MainWeapon->AttachActor(MainWeapon->ReturnAttachSocketName());
			break;

		case true:
			MainWeapon->AttachActor(MainWeapon->ReturnHandSocketName());
			break;
		}
	}
}
