// Kevin-Brandon Corbett 2019


#include "OpenDoor.h"
#include "Math/Rotator.h"


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

	OpenDoor();
}

void UOpenDoor::OpenDoor()
{
	// Get Owner
	AActor* Owner = GetOwner();

	// Make Rotator
	FRotator NewRotator = FRotator
	(
		0.0f,
		90.0f,
		0.0f

	);

	// Set new Roatation
	Owner->SetActorRotation(NewRotator);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll The Trigger Volume
	if (PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpens)
	{
		// If the ActorThatOpens is in the volume
		OpenDoor();
	}


}

