// Kevin-Brandon Corbett 2019


#include "PositionReport_001.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UPositionReport_001::UPositionReport_001()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReport_001::BeginPlay()
{
	Super::BeginPlay();

	FString ObjectName = GetOwner()->GetName();
	FString ObjectPos = GetOwner()->GetActorLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("Position Report Reporting for Duty on %s at %s"), *ObjectName, *ObjectPos);
	
}


// Called every frame
void UPositionReport_001::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

