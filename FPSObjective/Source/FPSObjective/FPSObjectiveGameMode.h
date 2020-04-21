// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPSObjectiveGameMode.generated.h"

UCLASS(minimalapi)
class AFPSObjectiveGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFPSObjectiveGameMode();
	void MissionComplete(APawn* InstigatorPawn);

	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void OnMissionCompleted(APawn* InstigatorPawn);

	UPROPERTY(EditDefaultsOnly, Category = "Spectating")
	TSubclassOf<AActor> SpectatingCameraClass;

};



