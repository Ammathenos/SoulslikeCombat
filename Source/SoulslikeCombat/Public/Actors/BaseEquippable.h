// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseEquippable.generated.h"

UCLASS()
class SOULSLIKECOMBAT_API ABaseEquippable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseEquippable();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void OnEquipped();

	UFUNCTION(BlueprintCallable)
		void OnUnequipped();

	UFUNCTION(BlueprintCallable)
		void AttachActor(FName SocketName);

	FORCEINLINE FName ReturnAttachSocketName() { return AttachSocketName; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Initialization")
		FName AttachSocketName = "None";

	UFUNCTION(BlueprintCallable)
		void SetIsEquipped(bool IsEquipped);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool IsEquipped();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Item Mesh")
		UPrimitiveComponent* GetItemMesh();

private:
	UPROPERTY(VisibleAnywhere)
		TObjectPtr<UStaticMeshComponent> ItemStaticMesh;

	UPROPERTY(VisibleAnywhere)
		TObjectPtr<USkeletalMeshComponent> ItemSkeletalMesh;

	UPROPERTY(VisibleAnywhere)
		bool bIsEquipped = false;

	

};
