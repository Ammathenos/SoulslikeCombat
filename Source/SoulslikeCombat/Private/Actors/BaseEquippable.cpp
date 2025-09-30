// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseEquippable.h"
#include "GameFramework/Character.h"

// Sets default values
ABaseEquippable::ABaseEquippable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	ItemStaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ItemStaticMesh->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;
	ItemStaticMesh->SetupAttachment(GetRootComponent());

	ItemSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	ItemSkeletalMesh->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void ABaseEquippable::BeginPlay()
{
	Super::BeginPlay();
	
}

UPrimitiveComponent* ABaseEquippable::GetItemMesh()
{
	if (ItemStaticMesh->GetStaticMesh()) // ou "if (ItemStaticMesh->GetStaticMesh() == Cast<UStaticMesh>(ItemStaticMesh))"
	{
		return ItemStaticMesh;
	}
	return ItemSkeletalMesh;
}

void ABaseEquippable::OnEquipped()
{
	bIsEquipped = true;
	AttachActor(AttachSocketName);
}

void ABaseEquippable::OnUnequipped()
{
	if (bIsEquipped == true)
	{
		bIsEquipped = false;
	}
}

void ABaseEquippable::AttachActor(FName SocketName)
{
	USkeletalMeshComponent* CharacterMesh;

	if (Cast<ACharacter>(GetOwner())->GetMesh())
	{
		CharacterMesh = Cast<ACharacter>(GetOwner())->GetMesh();		
		AttachToComponent(CharacterMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, SocketName);
	}
}

void ABaseEquippable::SetIsEquipped(bool IsEquipped)
{
	bIsEquipped = IsEquipped;
}

bool ABaseEquippable::IsEquipped()
{
	return bIsEquipped;
}


// Called every frame
void ABaseEquippable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

