// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/PickUpActor.h"
#include "Actors/BaseEquippable.h"
#include "Actors/BaseWeapon.h"
#include "SoulslikeCombat/SoulslikeCombatCharacter.h"
#include "SoulslikeCombat/DebugMacros.h"

// Sets default values
APickUpActor::APickUpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickUpActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickUpActor::Interact(TObjectPtr<AActor> Caller)
{
	if (Caller)
	{
		if (GetWorld() && Item)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Cast<APawn>(Caller);

			ABaseEquippable* ItemSpawned;
			
			ItemSpawned = GetWorld()->SpawnActor<ABaseEquippable>(Item, GetActorTransform(), SpawnParams);

			if (ItemSpawned)
			{
				ItemSpawned->OnEquipped(Cast<ASoulslikeCombatCharacter>(Caller));
			}

		}
	}
}

