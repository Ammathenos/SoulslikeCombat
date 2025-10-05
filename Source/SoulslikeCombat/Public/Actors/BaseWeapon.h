// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseEquippable.h"
#include "Enums/CombatTypes.h"
#include "BaseWeapon.generated.h"

class UAnimMontage;
class UCombatComponent;

UCLASS()
class SOULSLIKECOMBAT_API ABaseWeapon : public ABaseEquippable
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = "Initialization")
		FName HandSocketName = "None";

	//* Returns HandSocketName
	FORCEINLINE FName ReturnHandSocketName() { return HandSocketName; }

	//* Overrided function from BaseEquippable, sets player character MainWeapon
	virtual void OnEquipped(ASoulslikeCombatCharacter* PlayerCharacter) override;

	UPROPERTY(EditAnywhere, Category = "Animations")
		UAnimMontage* EnterCombat;

	FORCEINLINE UAnimMontage* ReturnEnterCombatAnimMontage() { return EnterCombat; }

	UPROPERTY(EditAnywhere, Category = "Animations")
		UAnimMontage* ExitCombat;

	FORCEINLINE UAnimMontage* ReturnExitCombatAnimMontage() { return ExitCombat; }
	
	UPROPERTY(VisibleAnywhere, Category = "Initialization")
		ECombatTypes CombatType = ECombatTypes::ECT_None;

	UPROPERTY(VisibleAnywhere)
		UCombatComponent* PlayerCombatComponent;

private:
};
