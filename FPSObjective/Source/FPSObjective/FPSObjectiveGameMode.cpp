// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FPSObjectiveGameMode.h"
#include "FPSObjectiveHUD.h"
#include "FPSObjectiveCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPSObjectiveGameMode::AFPSObjectiveGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSObjectiveHUD::StaticClass();
}
void AFPSObjectiveGameMode::MissionComplete(APawn * InstigatorPawn)
{
	if (InstigatorPawn)
		{
			InstigatorPawn->DisableInput(nullptr);
		}
	OnMissionCompleted(InstigatorPawn);
}
