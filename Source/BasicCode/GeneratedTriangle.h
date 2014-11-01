

#pragma once

#include "GameFramework/Actor.h"
#include "GeneratedMeshComponent.h"
#include "GeneratedTriangle.generated.h"

/**
 * 
 */
UCLASS()
class BASICCODE_API AGeneratedTriangle : public AActor
{
	GENERATED_UCLASS_BODY()

	void Triangle(TArray<FGeneratedMeshTriangle>& triangles);

private:
	TSubobjectPtr<UGeneratedMeshComponent> mesh;
};
