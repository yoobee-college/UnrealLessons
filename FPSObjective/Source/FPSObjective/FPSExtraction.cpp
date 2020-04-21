// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSExtraction.h"
#include "Components/BoxComponent.h"
#include "FPSObjectiveCharacter.h"
#include "FPSObjectiveGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFPSExtraction::AFPSExtraction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapComp->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	OverlapComp->SetBoxExtent(FVector(200.0f));
	RootComponent = OverlapComp;

	OverlapComp->SetHiddenInGame(false);
	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AFPSExtraction::HandleOverlap);
}

// Called when the game starts or when spawned
void AFPSExtraction::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSExtraction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSExtraction::HandleOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapped with extraction zone"));
	AFPSObjectiveCharacter* MyPawn = Cast<AFPSObjectiveCharacter>(OtherActor);
	if (MyPawn == nullptr)
	{
		return;
	}

	if (MyPawn != nullptr && MyPawn->bIsCarryingObjective)
	{
		AFPSObjectiveGameMode* GM = Cast<AFPSObjectiveGameMode>(GetWorld()->GetAuthGameMode());
		if (GM)
		{
			GM->MissionComplete(MyPawn);
		}

	}
	else
	{
		UGameplayStatics::PlaySound2D(this, ObjectiveMissingSound);
	}

}

