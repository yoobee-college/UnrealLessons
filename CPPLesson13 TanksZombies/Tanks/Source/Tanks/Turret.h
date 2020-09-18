// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Turret.generated.h"

class UArrowComponent;
class UPaperSpriteComponent;
class ATank;
class AMissile;

UCLASS()
class TANKS_API ATurret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turret", meta = (AllowPrivateAccess = "true"))
		UArrowComponent* TurretDirection;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turret", meta = (AllowPrivateAccess = "true"))
		UPaperSpriteComponent* TurretSprite;

protected:
	// Max turn rate in degrees per second for the turret
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Turret")
		float YawSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turret")
		ATank* Tank;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Turret")
		TSubclassOf<class AMissile> Projectile;
};