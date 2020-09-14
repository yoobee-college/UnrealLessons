// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UArrowComponent;
class UPaperSpriteComponent;
class UCameraComponent;
class USpringArmComponent;

USTRUCT(BlueprintType)
struct FTankInput
{
	GENERATED_BODY()//To recognise by Unreal
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank Input")
	FVector2D MovementInput;

	void Sanitize();
	void MoveX(float AxisValue);
	void MoveY(float AxisValue);

private:
	FVector2D RawMovementInput;
};

UCLASS()
class TANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// for debugging
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank", meta = (AllowPrivateAccess = "true"))
	UArrowComponent* TankDirection;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank", meta = (AllowPrivateAccess = "true"))
		UPaperSpriteComponent* TankSprite;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turret", meta = (AllowPrivateAccess = "true"))
		UChildActorComponent* ChildTurret;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank", meta = (AllowPrivateAccess = "true"))
		UCameraComponent* CameraComponent;

	USpringArmComponent* SpringArm;

private:
	void MoveX(float AxisValue);
	void MoveY(float AxisValue);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank Input")
	FTankInput TankInput;
};
