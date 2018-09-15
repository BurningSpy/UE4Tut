// Gregor Läufer 2018

#include "SecondPosReport.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
USecondPosReport::USecondPosReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USecondPosReport::BeginPlay()
{
	Super::BeginPlay();

	FString ObjectName = GetOwner()->GetName(); 
	FString ObjectPos = GetOwner()->GetActorLocation().ToCompactString();

	UE_LOG(LogTemp, Warning, TEXT("%s is at %s !!"), *ObjectName, *ObjectPos)
}


// Called every frame
void USecondPosReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

