// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FPSObjectiveGameMode.h"
#include "FPSObjectiveHUD.h"
#include "FPSObjectiveCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

AFPSObjectiveGameMode::AFPSObjectiveGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSObjectiveHUD::StaticClass();
}
void AFPSObjectiveGameMode::MissionComplete(APawn * InstigatorPawn, bool MissionComplete)
{
	if (InstigatorPawn)
	{
		InstigatorPawn->DisableInput(nullptr);
		if (SpectatingCameraClass)
		{
			AActor* NewViewTarget = nullptr;
			TArray<AActor*> ReturnedActors;
			UGameplayStatics::GetAllActorsOfClass(this, SpectatingCameraClass, ReturnedActors);
			if (ReturnedActors.Num() > 0)
			{
				NewViewTarget = ReturnedActors[0];
				APlayerController* PC = Cast<APlayerController>(InstigatorPawn->GetController());
				if (PC)
				{
					PC->SetViewTargetWithBlend(NewViewTarget, 1.0f, EViewTargetBlendFunction::VTBlend_Cubic);
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Cannot find Spectating Camera Class. Please Update Game Mode"))
		}
	}
	OnMissionCompleted(InstigatorPawn, MissionComplete);
}
