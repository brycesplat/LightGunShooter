// Copyright Epic Games, Inc. All Rights Reserved.

#include "LightGunShooterGameMode.h"
#include "LightGunShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALightGunShooterGameMode::ALightGunShooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
