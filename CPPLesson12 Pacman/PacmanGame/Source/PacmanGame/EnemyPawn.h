// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyPawn.generated.h"

UENUM(BlueprintType)
enum class EEnemyState : uint8 {
	Default,
	Idle
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnmemyStateChangedEvent, EEnemyState, NewState);

UCLASS()
class PACMANGAME_API AEnemyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEnemyState State = EEnemyState::Default;

	UFUNCTION(BlueprintCallable)
		void Hunt();

	UFUNCTION(BlueprintCallable)
		void Idle();

	FEnmemyStateChangedEvent& OnStateChanged() { return StateChangedEvent; }

private:
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FEnmemyStateChangedEvent StateChangedEvent;
};
