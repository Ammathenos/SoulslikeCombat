// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifies/AttachWeaponActor.h"
#include "SoulslikeCombat/SoulslikeCombatCharacter.h"
#include "Components/CombatComponent.h"
#include "Actors/BaseWeapon.h"

void UAttachWeaponActor::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (!MeshComp) return;

	ASoulslikeCombatCharacter* PlayerCharacter = Cast<ASoulslikeCombatCharacter>(MeshComp->GetOwner());
	if (!PlayerCharacter) return;

	UCombatComponent* PlayerCombatComponent = PlayerCharacter->GetCombatComponent();
	if (!PlayerCombatComponent) return;

	if (ABaseWeapon* PlayerWeapon = PlayerCombatComponent->GetMainWeapon())
	{
		PlayerWeapon->AttachActor(AttachSocketName, PlayerCharacter);
	}
	else return;

}
