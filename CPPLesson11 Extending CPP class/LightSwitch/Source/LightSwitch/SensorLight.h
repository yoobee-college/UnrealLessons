// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SensorLight.generated.h"

class UPointLightComponent;
UCLASS()
class LIGHTSWITCH_API ASensorLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASensorLight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Switch Components")
		class UPointLightComponent* PointLight1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Switch Components")
		class USphereComponent* Sphere1;

	UPROPERTY(EditAnywhere, Category = "Switch Variables")
		float DesiredIntensity;

	UFUNCTION()
	virtual void NotifyActorBeginOverlap(AActor* OtherActor);

	UFUNCTION()
	virtual void NotifyActorEndOverlap(AActor* OtherActor);

	UFUNCTION(BlueprintCallable, Category = "Switch Functions")
		void CharacterOverlap(FLinearColor DefaultColour);
};
