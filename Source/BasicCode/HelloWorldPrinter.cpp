

#include "BasicCode.h"
#include "HelloWorldPrinter.h"


AHelloWorldPrinter::AHelloWorldPrinter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
	, Number(42)
{
	if (GEngine)
	{
		UE_LOG(GameInit, Log, TEXT("AHelloWorldPrinter: ctor"));
		GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Green, FString("AHelloWorldPrinter: ctor"));
	}
	else
	{
		UE_LOG(GameInit, Warning, TEXT("AHelloWorldPrinter: ctor (GEngine null)"));
	}
}

void AHelloWorldPrinter::BeginPlay()
{
	Super::BeginPlay();


	if (GEngine)
	{
		FString Message = FString::Printf(TEXT("AHelloWorldPrinter: BeginPlay Number=%d"), Number);
		GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Yellow, *Message);

		UE_LOG(GameInit, Log, TEXT("AHelloWorldPrinter: BeginPlay Number=%d"), Number);
	}
	else
	{
		// TODO SRombauts: possible?
		UE_LOG(GameInit, Error, TEXT("AHelloWorldPrinter: BeginPlay Number=%d"), Number);
	}
}

