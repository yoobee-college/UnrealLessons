// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Brick_PC.generated.h"

/**
 * 
 */
UCLASS()
class BRICKGAME_API ABrick_PC : public APlayerController
{
	GENERATED_BODY()

	ABrick_PC();
	UFUNCTION()
		virtual void SetupInputComponent() override;

protected:
	virtual void BeginPlay() override;
	void MoveHorizontal(float AxisValue);
};
