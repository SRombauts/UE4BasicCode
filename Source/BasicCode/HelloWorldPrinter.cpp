

#include "BasicCode.h"
#include "HelloWorldPrinter.h"


AHelloWorldPrinter::AHelloWorldPrinter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	UE_LOG(GameInit, Log, TEXT("AHelloWorldPrinter: ctor"));
	Number = 42;
}

void AHelloWorldPrinter::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(GameInit, Log, TEXT("AHelloWorldPrinter: BeginPlay"));

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Yellow, TEXT("Hello World!"));
		GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Yellow, FString::FromInt(Number));
	}
}

