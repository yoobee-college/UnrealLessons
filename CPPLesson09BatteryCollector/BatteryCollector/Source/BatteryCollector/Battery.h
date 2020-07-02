// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Battery.generated.h"

class UBoxComponent;
class USceneComponent;

UCLASS()
class BATTERYCOLLECTOR_API ABattery : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattery();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnyWhere, Category = "Component")
		UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnyWhere, Category = "Component")
		UBoxComponent* BoxComp;

	UPROPERTY(VisibleAnyWhere, Category = "Component")
		USceneComponent* SceneComp;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
		UParticleSystem* PicksupFX;

	void PlayEffects();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor);
};
