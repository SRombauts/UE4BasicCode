

#include "BasicCode.h"
#include "GeneratedTriangle.h"

// TODO : moving artifacts only when triangle is horizontal?

// TODO : Update code in the wiki: you would need to have a separate function in the actor for generating the mesh. You could then do spawn actor, set material, generate mesh, mesh->SetMaterial(0, Material);

// TODO : applying a material (with UV)
// TODO : smooth normals?
// TODO : using triangles strip?

AGeneratedTriangle::AGeneratedTriangle(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	mesh = PCIP.CreateDefaultSubobject<UGeneratedMeshComponent>(this, TEXT("GeneratedMesh"));

//	static ConstructorHelpers::FObjectFinder<UMaterialInterface> Material(TEXT("Material'/Game/Materials/BaseColor.BaseColor'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> Material(TEXT("Material'/Game/Materials/M_Concrete_Poured.M_Concrete_Poured'"));
	mesh->SetMaterial(0, Material.Object);

	TArray<FGeneratedMeshTriangle> triangles;
	Triangle(triangles);
	mesh->SetGeneratedMeshTriangles(triangles);

	RootComponent = mesh;
}

// Generate a single horizontal triangle counterclockwise to point up (invisible from the bottom)
void AGeneratedTriangle::Triangle(TArray<FGeneratedMeshTriangle>& triangles)
{
	FGeneratedMeshTriangle triangle;
	triangle.Vertex0.Position.Set(100.f, -80.f, -60.f);
	triangle.Vertex1.Position.Set(100.f, 80.f, -30.f);
	triangle.Vertex2.Position.Set(200.f, 0.f, 0.f);
	static const FColor Blue(51, 51, 255);
	triangle.Vertex0.Color = Blue;
	triangle.Vertex1.Color = Blue;
	triangle.Vertex2.Color = Blue;
	triangle.Vertex0.U = 0.0f;
	triangle.Vertex0.V = 0.0f;
	triangle.Vertex1.U = 1.0f;
	triangle.Vertex1.V = 0.0f;
	triangle.Vertex2.U = 0.5f;
	triangle.Vertex2.V = 0.75f;
	triangles.Add(triangle);
}
