// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "StealthGameMode.h"
#include "StealthHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"
//#include "NavMesh/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "ActorPool.h"

AStealthGameMode::AStealthGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Dynamic/Character/Behavior/BP_Character"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AStealthHUD::StaticClass();

	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(FName("Nav Mesh Bounds Volume Pool"));
}

void AStealthGameMode::PopulateBoundsVolumePool()
{
	
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), FoundActors);

	for (AActor* TActor : FoundActors)
	{
		AActor* MyActor = Cast<AActor>(TActor);

		if (MyActor != nullptr)
		{
			AddToPool(MyActor);
		}
	}

}


void AStealthGameMode::AddToPool(AActor* VolumeToAdd)
{
	NavMeshBoundsVolumePool->Add(VolumeToAdd);
}
