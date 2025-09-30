// Copyright Epic Games, Inc. All Rights Reserved.

#include "SoulslikeCombatGameMode.h"
#include "SoulslikeCombatCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASoulslikeCombatGameMode::ASoulslikeCombatGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/CombatSystem/Blueprints/BP_CombatCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
