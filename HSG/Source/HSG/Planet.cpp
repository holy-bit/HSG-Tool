// Fill out your copyright notice in the Description page of Project Settings.


#include "Planet.h"

// Sets default values
APlanet::APlanet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CustomMesh = CreateDefaultSubobject<UProceduralMeshComponent>("CustomMesh");
	//CustomMesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	SetRootComponent(CustomMesh);
	CustomMesh->bUseAsyncCooking = true;

}

// Called when the game starts or when spawned
void APlanet::BeginPlay()
{
	Super::BeginPlay();
	OnConstruction(GetRootComponent()->GetComponentTransform());
}

 void APlanet::AddTriangle(int32 V1, int32 V2, int32 V3)
 {
 	triangles.Add(V1);
 	triangles.Add(V2);

 	triangles.Add(V3);
 }


void APlanet::OnConstruction(const FTransform& Transform)
{
	ClearMeshData();

	//6 sides on cube, 4 verts each (corners)

	//These are relative locations to the placed Actor in the world
 	//vertices.Add(FVector(0, -100, 0)); //lower left - 0
 	//vertices.Add(FVector(0, -100, 100)); //upper left - 1
 	//vertices.Add(FVector(0, 100, 0)); //lower right - 2 
 	//vertices.Add(FVector(0, 100, 100)); //upper right - 3
 
 	//vertices.Add(FVector(100, -100, 0)); //lower front left - 4
 	//vertices.Add(FVector(100, -100, 100)); //upper front left - 5
 
 	//vertices.Add(FVector(100, 100, 100)); //upper front right - 6
 	//vertices.Add(FVector(100, 100, 0)); //lower front right - 7
 
 	////Back face of cube
 	//AddTriangle(0, 2, 3);
 	//AddTriangle(3, 1, 0);
 
 	////Left face of cube
 	//AddTriangle(0, 1, 4);
 	//AddTriangle(4, 1, 5);
 
 	////Front face of cube
 	//AddTriangle(4, 5, 7);
 	//AddTriangle(7, 5, 6);
 
 	////Right face of cube
 	//AddTriangle(7, 6, 3);
 	//AddTriangle(3, 2, 7);
 
 	////Top face
 	//AddTriangle(1, 3, 5);
 	//AddTriangle(6, 5, 3);
 
 	////bottom face
 	//AddTriangle(2, 0, 4);
 	//AddTriangle(4, 7, 2);
 
 	//vertexColors.Add(FLinearColor(0.f, 0.f, 1.f));
 	//vertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
 	//vertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
 	//vertexColors.Add(FLinearColor(0.f, 1.f, 0.f));
 	//vertexColors.Add(FLinearColor(0.5f, 1.f, 0.5f));
 	//vertexColors.Add(FLinearColor(0.f, 1.f, 0.f));
 	//vertexColors.Add(FLinearColor(1.f, 1.f, 0.f));
 	//vertexColors.Add(FLinearColor(0.f, 1.f, 1.f));

// 	const float X = .525731112119133606f;
// 	const float Z = .850650808352039932f;
// 	const float N = 0.f;
 
 	vertices.Add(icosahedron::vertices[0]);
 	vertices.Add(icosahedron::vertices[1]);
 	vertices.Add(icosahedron::vertices[2]);
 	vertices.Add(icosahedron::vertices[3]);
 	vertices.Add(FVector(icosahedron::vertices[4]));
 	vertices.Add(FVector(icosahedron::vertices[5]));
 	vertices.Add(FVector(icosahedron::vertices[6]));
 	vertices.Add(FVector(icosahedron::vertices[7]));
 	vertices.Add(FVector(icosahedron::vertices[8]));
 	vertices.Add(FVector(icosahedron::vertices[9]));
 	vertices.Add(FVector(icosahedron::vertices[10]));
 	vertices.Add(FVector(icosahedron::vertices[11]));
 
 	AddTriangle(icosahedron::triangles[0].vertices.X, icosahedron::triangles[0].vertices.Y, icosahedron::triangles[0].vertices.Z);
	AddTriangle(icosahedron::triangles[1].vertices.X, icosahedron::triangles[1].vertices.Y, icosahedron::triangles[1].vertices.Z);
	AddTriangle(icosahedron::triangles[2].vertices.X, icosahedron::triangles[2].vertices.Y, icosahedron::triangles[2].vertices.Z);
	AddTriangle(icosahedron::triangles[3].vertices.X, icosahedron::triangles[3].vertices.Y, icosahedron::triangles[3].vertices.Z);
	AddTriangle(icosahedron::triangles[4].vertices.X, icosahedron::triangles[4].vertices.Y, icosahedron::triangles[4].vertices.Z);
	AddTriangle(icosahedron::triangles[5].vertices.X, icosahedron::triangles[5].vertices.Y, icosahedron::triangles[5].vertices.Z);
	AddTriangle(icosahedron::triangles[6].vertices.X, icosahedron::triangles[6].vertices.Y, icosahedron::triangles[6].vertices.Z);
	AddTriangle(icosahedron::triangles[7].vertices.X, icosahedron::triangles[7].vertices.Y, icosahedron::triangles[7].vertices.Z);
	AddTriangle(icosahedron::triangles[8].vertices.X, icosahedron::triangles[8].vertices.Y, icosahedron::triangles[8].vertices.Z);
	AddTriangle(icosahedron::triangles[9].vertices.X, icosahedron::triangles[9].vertices.Y, icosahedron::triangles[9].vertices.Z);
	AddTriangle(icosahedron::triangles[10].vertices.X, icosahedron::triangles[10].vertices.Y, icosahedron::triangles[10].vertices.Z);
	AddTriangle(icosahedron::triangles[11].vertices.X, icosahedron::triangles[11].vertices.Y, icosahedron::triangles[11].vertices.Z);
	AddTriangle(icosahedron::triangles[12].vertices.X, icosahedron::triangles[12].vertices.Y, icosahedron::triangles[12].vertices.Z);
	AddTriangle(icosahedron::triangles[13].vertices.X, icosahedron::triangles[13].vertices.Y, icosahedron::triangles[13].vertices.Z);
	AddTriangle(icosahedron::triangles[14].vertices.X, icosahedron::triangles[14].vertices.Y, icosahedron::triangles[14].vertices.Z);
	AddTriangle(icosahedron::triangles[15].vertices.X, icosahedron::triangles[15].vertices.Y, icosahedron::triangles[15].vertices.Z);
	AddTriangle(icosahedron::triangles[16].vertices.X, icosahedron::triangles[16].vertices.Y, icosahedron::triangles[16].vertices.Z);
	AddTriangle(icosahedron::triangles[17].vertices.X, icosahedron::triangles[17].vertices.Y, icosahedron::triangles[17].vertices.Z);
	AddTriangle(icosahedron::triangles[18].vertices.X, icosahedron::triangles[18].vertices.Y, icosahedron::triangles[18].vertices.Z);
	AddTriangle(icosahedron::triangles[19].vertices.X, icosahedron::triangles[19].vertices.Y, icosahedron::triangles[19].vertices.Z);

 	
 
 	vertexColors.Add(FLinearColor(0.f, 0.f, 1.f));
 	vertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
 	vertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
 	vertexColors.Add(FLinearColor(0.f, 1.f, 0.f));
 	vertexColors.Add(FLinearColor(0.5f, 1.f, 0.5f));
 	vertexColors.Add(FLinearColor(0.f, 1.f, 0.f));
 	vertexColors.Add(FLinearColor(1.f, 1.f, 0.f));
 	vertexColors.Add(FLinearColor(0.f, 1.f, 1.f));
 	vertexColors.Add(FLinearColor(0.f, 1.f, 1.f));
 	vertexColors.Add(FLinearColor(0.f, 1.f, 1.f));
 	vertexColors.Add(FLinearColor(0.f, 1.f, 1.f));
 	vertexColors.Add(FLinearColor(0.f, 1.f, 1.f));

	CustomMesh->CreateMeshSection_LinearColor(0, vertices, triangles, TArray<FVector>(), TArray<FVector2D>(), vertexColors, TArray<FProcMeshTangent>(), true);

	CustomMesh->SetRelativeScale3D(FVector(500, 500, 500));

}


// void APlanet::subdivide(VertexList& vertices,
// 	TriangleList triangles)
// {
// 	Lookup lookup;
// 	TriangleList result;
// 
// 	for (auto&& each : triangles)
// 	{
// 		std::array<Index, 3> mid;
// 		for (int edge = 0; edge < 3; ++edge)
// 		{
// 			mid[edge] = vertex_for_edge(lookup, vertices,
// 				each.vertex[edge], each.vertex[(edge + 1) % 3]);
// 		}
// 
// 		result.push_back({ each.vertex[0], mid[0], mid[2] });
// 		result.push_back({ each.vertex[1], mid[1], mid[0] });
// 		result.push_back({ each.vertex[2], mid[2], mid[1] });
// 		result.push_back({ mid[0], mid[1], mid[2] });
// 	}
// 
// 	return result;
// }

void APlanet::ClearMeshData()
{
	vertices.Empty();
	triangles.Empty();
	uvs.Empty();
	normals.Empty();
	vertexColors.Empty();
	tangents.Empty();
}
