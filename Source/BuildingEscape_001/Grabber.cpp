// Kevin-Brandon Corbett 2019

#include "Grabber.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Grabber is reporting for duty!"));

}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	// Get Player ViewPoint
	FVector PlayerViewLocation;
	FRotator PlayerViewRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint
	(
		OUT PlayerViewLocation,
		OUT PlayerViewRotation
	);

	// UE_LOG(LogTemp, Warning, TEXT("Location: %s, Rotation: %s"), *PlayerViewLocation.ToString(), *PlayerViewRotation.ToString());

	FVector LineTraceEnd = PlayerViewLocation + PlayerViewRotation.Vector() * Reach;

	// Draw a red trace line in the world
	DrawDebugLine
	(
		GetWorld(),
		PlayerViewLocation,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.0f,
		0.0f,
		10.0f

	);

	// Ray-Cast

	// See what we hit
}

