// Fill out your copyright notice in the Description page of Project Settings.


#include "Battery.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BatteryCollectorCharacter.h"


// Sets default values
ABattery::ABattery()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("SphereComp"));
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = SceneComp;
	BoxComp->SetupAttachment(SceneComp);
	MeshComp->SetupAttachment(SceneComp);


	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

}

// Called when the game starts or when spawned
void ABattery::BeginPlay()
{
	Super::BeginPlay();
	//PlayEffects();
	
}

// Called every frame
void ABattery::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABattery::PlayEffects()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, PicksupFX, GetActorLocation());
}

void ABattery::NotifyActorBeginOverlap(AActor* OtherActor)
{
	ABatteryCollectorCharacter* OverlapChar = Cast<ABatteryCollectorCharacter>(OtherActor);
	if (OverlapChar)
	{
		OverlapChar->BatteryCollected++;
		Super::NotifyActorBeginOverlap(OtherActor);
		PlayEffects();
		Destroy();
		UE_LOG(LogTemp, Warning, TEXT("overlap %d"), OverlapChar->BatteryCollected);
	}
}

