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

	/// Look for attahced physics handle

	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle)
	{
		/// physics handle is found
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s missing physics handle component!"), *GetOwner()->GetName());
	}
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

	/// Setup query params
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());


	// Ray-Cast
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType
	(
		OUT Hit,
		PlayerViewLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);


	// See what we hit
	AActor* ActorHit = Hit.GetActor();
	if (ActorHit)
		{
			UE_LOG(LogTemp, Warning, TEXT("LineTraceHit: %s"), *(ActorHit->GetName()));
		}
}

