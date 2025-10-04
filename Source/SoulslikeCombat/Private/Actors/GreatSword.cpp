// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/GreatSword.h"

AGreatSword::AGreatSword()
{
	AttachSocketName = "GreatSwordBackSocket";
	HandSocketName = "GreatSwordHandSocket";
	CombatType = ECombatTypes::ECT_GreatSword;
}
