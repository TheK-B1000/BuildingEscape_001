// Kevin-Brandon Corbett 2019


#include "OpenDoor_001.h"
#include "Math/Rotator.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UOpenDoor_001::UOpenDoor_001()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor_001::BeginPlay()
{
	Super::BeginPlay();

	// Set Actor
	AActor* Owner = GetOwner();

	// Make Rotator
	FRotator NewRotator = FRotator(0.0f, 90.0f, 0.0f);

	// Set Rotation
	Owner->SetActorRotation(NewRotator);
}


// Called every frame
void UOpenDoor_001::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
