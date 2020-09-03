// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitch.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ALightSwitch::ALightSwitch()
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
void ALightSwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALightSwitch::NotifyActorBeginOverlap(AActor* OtherActor)
{

	PointLight1->ToggleVisibility();
	
}

void ALightSwitch::NotifyActorBeginOverlap_imp(AActor* OtherActor)
{
	PointLight1->ToggleVisibility();
}

void ALightSwitch::NotifyActorEndOverlap(AActor* OtherActor)
{

	PointLight1->ToggleVisibility();

}

void ALightSwitch::NotifyActorEndOverlap_imp(AActor* OtherActor)
{
	PointLight1->ToggleVisibility();
}
