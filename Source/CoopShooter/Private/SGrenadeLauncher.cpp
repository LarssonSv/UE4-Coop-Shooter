// Fill out your copyright notice in the Description page of Project Settings.

#include "SGrenadeLauncher.h"
#include <Engine/World.h>
#include "Components/SkeletalMeshComponent.h"

void ASGrenadeLauncher::Fire()
{
	if (Grenade)
	{
	
		AActor* MyOwner = GetOwner();

		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(Owner);
		QueryParams.AddIgnoredActor(this);

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParams.Owner = MyOwner;

		AActor* temp = GetWorld()->SpawnActor<AActor>(Grenade, MeshComp->GetSocketLocation(MuzzelSocketName), MyOwner->GetActorForwardVector().Rotation(), SpawnParams);
	}

}
