// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	// ...
	
}

void UOpenDoor::OpenDoor()
{
	AActor *Owner = GetOwner();
	FString DoorRotation = Owner->GetTransform().GetRotation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("Rotation Report for door: \n%s"), *DoorRotation);
	FRotator NewRotation = FRotator(0.0f, -210.0f, 0.0f);
	Owner->SetActorRotation(NewRotation);
	UE_LOG(LogTemp, Warning, TEXT("Rotation Report for door: \n%s"), *DoorRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate->IsOverlappingActor(ActorThatOpens)) 
	{
		OpenDoor();
	}
}

