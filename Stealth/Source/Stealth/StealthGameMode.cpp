// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "StealthGameMode.h"
#include "StealthHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStealthGameMode::AStealthGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Static/Player/Behavior/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AStealthHUD::StaticClass();
}
