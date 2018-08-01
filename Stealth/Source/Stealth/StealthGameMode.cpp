// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "StealthGameMode.h"
#include "StealthHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"
//#include "AI/Navigation/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"

AStealthGameMode::AStealthGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Dynamic/Character/Behavior/BP_Character"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AStealthHUD::StaticClass();
}

void AStealthGameMode::PopulateBoundsVolumePool()
{
	//TSubclassOf<AActor> ClassToFind;
	//ClassToFind = AActor::StaticClass();
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), FoundActors);
	UE_LOG(LogTemp, Warning, TEXT("Found Actor: %s"), FoundActors)
	AddToPool(FoundActors);
}


void AStealthGameMode::AddToPool(TArray<AActor*> VolumeToAdd)
{
//UE_LOG(LogTemp, Warning, TEXT("Found Actor: %s"), VolumeToAdd);
}
