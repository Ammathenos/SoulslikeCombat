// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ToughSword.h"

AToughSword::AToughSword()
{
	AttachSocketName = "SwordHipAttachSocket";
	HandSocketName = "WeaponSocket";
	CombatType = ECombatTypes::ECT_LightSword;
}
