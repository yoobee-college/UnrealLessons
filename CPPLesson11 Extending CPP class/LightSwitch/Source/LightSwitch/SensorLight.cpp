// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "SensorLight.h"

// Sets default values
ASensorLight::ASensorLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DesiredIntensity = 10000.0f;

	PointLight1 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight1"));
	PointLight1->Intensity = DesiredIntensity;
	PointLight1->bVisible = true;
	RootComponent = PointLight1;

	Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Sphere1->InitSphereRadius(250.0f);
	Sphere1->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASensorLight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASensorLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ASensorLight::NotifyActorBeginOverlap(AActor* OtherActor)
{

	//PointLight1->ToggleVisibility();
	CharacterOverlap(FLinearColor(1.0f, 0.2f, 0.2f));
}

void ASensorLight::NotifyActorEndOverlap(AActor* OtherActor)
{
	CharacterOverlap(FLinearColor(1.0f, 1.0f, 1.0f));
	//PointLight1->ToggleVisibility();

}

void ASensorLight::CharacterOverlap(FLinearColor DefaultColour)
{
	//PointLight1->SetLightColor(FLinearColor(1.0f,0.2f,0.2f));
	PointLight1->SetLightColor(DefaultColour);
}
