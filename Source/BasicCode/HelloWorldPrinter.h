

#pragma once

#include "GameFramework/Actor.h"
#include "HelloWorldPrinter.generated.h"

/**
 * 
 */
UCLASS()
class BASICCODE_API AHelloWorldPrinter : public AActor
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY(EditAnywhere, Category=Actor)
	uint32 Number;

public:
	virtual void BeginPlay() override;
};
