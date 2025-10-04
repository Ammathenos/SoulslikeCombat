// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interactable.h"
#include "PickUpActor.generated.h"

class ABaseEquippable;

UCLASS()
class SOULSLIKECOMBAT_API APickUpActor : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//* Interact function overrided from IInteractable interface, spawn and equips a BaseEquippable to player character
	virtual void Interact(TObjectPtr<AActor> Caller) override;

	UPROPERTY(EditAnywhere, Category = "SpawnEquip")
		TSubclassOf<ABaseEquippable> Item;
};
