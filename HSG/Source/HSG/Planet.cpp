// Fill out your copyright notice in the Description page of Project Settings.


#include "Planet.h"
DEFINE_LOG_CATEGORY(LogMyGame);
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

 FVector APlanet::getMiddle(FVector& v1, FVector& v2)
 {
	 //The golden ratio
	 float t = (1 + sqrt(5)) / 2;

	 FVector temporaryVector;

	 //Calculate the middle
	 temporaryVector = (v2 - v1) * 0.5 + v1;

	 //Offset poin
	 temporaryVector.Normalize();
	 temporaryVector *= sqrt(t * t + 1) * 50;

	 return temporaryVector;
 }

 FVector2D APlanet::getMiddle(FVector2D& v1, FVector2D& v2)
 {

	 FVector2D temporaryVector;

	 //Calculate the middle
	 temporaryVector = (v2 - v1) * 0.5 + v1;

	 return temporaryVector;
 }


 void APlanet::subdivideIcosahedron()
 {
	 subdivideTriangles();
 }

 void APlanet::subdivideUVs()
 {
	 //TArray<FVector2D> newUV;

	 //FVector2D newVector1;
	 //FVector2D newVector2;
	 //FVector2D newVector3;
	 //for (int i = 0; i &lt; vertices.Count; i += 3)
	 //{
		// //Find the middle points
		// newVector1 = getMiddle(UV[i], UV[i + 1]);
		// newVector2 = getMiddle(UV[i + 1], UV[i + 2]);
		// newVector3 = getMiddle(UV[i + 2], UV[i]);

		// //Add the new faces
		// newUV.Add(newVector3);
		// newUV.Add(UV[i]);
		// newUV.Add(newVector1);

		// newUV.Add(newVector1);
		// newUV.Add(UV[i + 1]);
		// newUV.Add(newVector2);

		// newUV.Add(newVector2);
		// newUV.Add(UV[i + 2]);
		// newUV.Add(newVector3);

		// newUV.Add(newVector1);
		// newUV.Add(newVector2);
		// newUV.Add(newVector3);
	 //}
	 ////Replace old points with new
	 //UV = newUV;
 }

 void APlanet::subdivideTriangles()
 {
	 float t = (1 + sqrt(5)) / 2;
	 TArray<FVector> newVertices;
	 TArray<int32> newindex;

	 FVector newVector1;
	 FVector newVector2;
	 FVector newVector3;
	 int32 x = 0;
	 UE_LOG(LogMyGame, Warning, TEXT("MyCharacter's Health is %d"), mesh.index.Num());
	 for (int i = 0; i < mesh.index.Num() - 2; i += 3)
	 {
		 //Find the middle points
		 newVector1 = getMiddle(mesh.vertices[mesh.index[i]], mesh.vertices[mesh.index[i + 1]]);
		 newVector2 = getMiddle(mesh.vertices[mesh.index[i + 1]], mesh.vertices[mesh.index[i + 2]]);
		 newVector3 = getMiddle(mesh.vertices[mesh.index[i + 2]], mesh.vertices[mesh.index[i]]);

		 //Add the new faces
		 newVertices.Add(newVector3);
		 newVertices.Add(mesh.vertices[mesh.index[i]]);
		 newVertices.Add(newVector1);

		 /////
		 newindex.Add(x);
		 x++;
		 newindex.Add(x);
		 x++;
		 newindex.Add(x);
		 x++;

		 newVertices.Add(newVector1);
		 newVertices.Add(mesh.vertices[mesh.index[i + 1]]);
		 newVertices.Add(newVector2);

		 newindex.Add(x);
		 x++;
		 newindex.Add(x);
		 x++;
		 newindex.Add(x);
		 x++;

		 newVertices.Add(newVector2);
		 newVertices.Add(mesh.vertices[mesh.index[i + 2]]);
		 newVertices.Add(newVector3);

		 newindex.Add(x);
		 x++;
		 newindex.Add(x);
		 x++;
		 newindex.Add(x);
		 x++;

		 newVertices.Add(newVector1);
		 newVertices.Add(newVector2);
		 newVertices.Add(newVector3);

		 newindex.Add(x);
		 x++;
		 newindex.Add(x);
		 x++;
		 newindex.Add(x);
		 x++;
	 }
	 //Replace old points with new
	 mesh.vertices = newVertices;
	 mesh.index = newindex;
 }

 void APlanet::CreateTriangle()
 {
	 vertices.Add(FVector(0.0f, 0.0f, 0.0f));
	 vertices.Add(FVector(100.0f, 0.0f, 0.0f));
	 vertices.Add(FVector(0.0f, 100.0f, 0.0f));

	 triangles.Add(0);
	 triangles.Add(2);
	 triangles.Add(1);

	 uvs.Add(FVector2D(0.0f, 0.0f));
	 uvs.Add(FVector2D(1.0f, 0.0f));
	 uvs.Add(FVector2D(0.0f, 1.0f));

	 //uvs.Init(FVector2D(0.0f, 0.0f), 3);
	 normals.Init(FVector(0.0f, 0.0f, 1.0f), 3);
	 vertexColors.Init(FLinearColor(0.0f, 0.0f, 0.0f, 1.0f), 3);
	 tangents.Init(FProcMeshTangent(1.0f, 0.0f, 0.0f), 3);

	 //Function that creates mesh section
	 CustomMesh->CreateMeshSection_LinearColor(0, vertices, triangles, normals, uvs, vertexColors, tangents, false);
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
	mesh = FMesh(icosahedron::vertices);
//  	vertices.Add(icosahedron::vertices[0]);
//  	vertices.Add(icosahedron::vertices[1]);
//  	vertices.Add(icosahedron::vertices[2]);
//  	vertices.Add(icosahedron::vertices[3]);
//  	vertices.Add(FVector(icosahedron::vertices[4]));
//  	vertices.Add(FVector(icosahedron::vertices[5]));
//  	vertices.Add(FVector(icosahedron::vertices[6]));
//  	vertices.Add(FVector(icosahedron::vertices[7]));
//  	vertices.Add(FVector(icosahedron::vertices[8]));
//  	vertices.Add(FVector(icosahedron::vertices[9]));
//  	vertices.Add(FVector(icosahedron::vertices[10]));
//  	vertices.Add(FVector(icosahedron::vertices[11]));

	for (int i =0;i<20;i++)
	{
		mesh.AddTriangle(icosahedron::triangles[i][0], icosahedron::triangles[i][1], icosahedron::triangles[i][2]);
	}
 

	//subdivideIcosahedron();
	//subdivideIcosahedron();
	//subdivideIcosahedron();
	//subdivideIcosahedron();
 	/*AddTriangle(icosahedron::triangles[0].vertices.X, icosahedron::triangles[0].vertices.Y, icosahedron::triangles[0].vertices.Z);
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
*/

// 	
// 	uvs.Add(FVector2D(0, 0));
// 	uvs.Add(FVector2D(10, 0));
// 	uvs.Add(FVector2D(0, 10));
// 	uvs.Add(FVector2D(0, 0));
// 	uvs.Add(FVector2D(10, 0));
// 	uvs.Add(FVector2D(0, 10));
// 	uvs.Add(FVector2D(0, 0));
// 	uvs.Add(FVector2D(10, 0));
// 	uvs.Add(FVector2D(0, 10));
// 	uvs.Add(FVector2D(0, 0));
// 	uvs.Add(FVector2D(10, 0));
// 	uvs.Add(FVector2D(0, 10));
//  
//  	vertexColors.Add(FLinearColor::MakeRandomColor());
//  	vertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
//  	vertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
//  	vertexColors.Add(FLinearColor(0.f, 1.f, 0.f));
//  	vertexColors.Add(FLinearColor(0.5f, 1.f, 0.5f));
//  	vertexColors.Add(FLinearColor(0.f, 1.f, 0.f));
//  	vertexColors.Add(FLinearColor(1.f, 1.f, 0.f));
//  	vertexColors.Add(FLinearColor(0.f, 1.f, 1.f));
//  	vertexColors.Add(FLinearColor(0.f, 1.f, 1.f));
//  	vertexColors.Add(FLinearColor(0.f, 1.f, 1.f));
//  	vertexColors.Add(FLinearColor(0.f, 1.f, 1.f));
//  	vertexColors.Add(FLinearColor(0.f, 1.f, 1.f));
	//CustomMesh->SetMaterial(0, material);
	//CustomMesh->CreateMeshSection_LinearColor(0, mesh.vertices, mesh.index, TArray<FVector>(), TArray<FVector2D>(), TArray<FLinearColor>(), TArray<FProcMeshTangent>(), true);
	CreateTriangle();
	//CustomMesh->SetRelativeScale3D(FVector(500, 500, 500));

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
