// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
//#include "Math/UnrealMathUtility.h"
#include <map>
#include "Planet.generated.h"


using namespace std;
USTRUCT()
struct FMeshTrianglew
{
	GENERATED_BODY()
public:
	UPROPERTY()
		FVector vertices;
	UPROPERTY()
		TArray<FVector> normals;
	UPROPERTY()
		TArray<FVector2D> uvs;
	UPROPERTY()
		TArray<FLinearColor> vertexColors;
	UPROPERTY()
		TArray<FProcMeshTangent> tangents;
	FMeshTrianglew(float X = 0, float Y = 0, float Z = 0)
	{
		vertices = FVector(X, Y, Z);
	}
	
};
typedef  TArray<FMeshTrianglew> TriangleList;
typedef  TArray<FVector> VertexList;
namespace icosahedron
{
	const float X = .525731112119133606f;
	const float Z = .850650808352039932f;
	const float N = 0.f;

	static const VertexList vertices =
	{
	  {-X,N,Z}, {X,N,Z}, {-X,N,-Z}, {X,N,-Z},
	  {N,Z,X}, {N,Z,-X}, {N,-Z,X}, {N,-Z,-X},
	  {Z,X,N}, {-Z,X, N}, {Z,-X,N}, {-Z,-X, N}
	};

	static const TriangleList triangles =
	{
	  {0,4,1},{0,9,4},{9,5,4},{4,5,8},{4,8,1},
	  {8,10,1},{8,3,10},{5,3,8},{5,2,3},{2,7,3},
	  {7,10,3},{7,6,10},{7,11,6},{11,0,6},{0,1,6},
	  {6,1,10},{9,0,11},{9,11,2},{9,2,5},{7,2,11}
	};
}

UCLASS()
class HSG_API APlanet : public AActor
{
	GENERATED_BODY()
		
	
	
public:	
	// Sets default values for this actor's properties
	APlanet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UProceduralMeshComponent* CustomMesh;
	
	UPROPERTY()
		TArray<FVector> vertices;
	UPROPERTY()
		TArray<FVector> normals;
	UPROPERTY()
		TArray<int32> triangles;
	UPROPERTY()
		TArray<FVector2D> uvs;
	UPROPERTY()
		TArray<FLinearColor> vertexColors;
	UPROPERTY()
		TArray<FProcMeshTangent> tangents;
	/* Creates a triangle that connects the given vertices */
	void AddTriangle(int32 V1, int32 V2, int32 V3);
	virtual void OnConstruction(const FTransform& Transform) override;

// 	using Lookup = std::map<std::pair<Index, Index>, Index>;
// 
// 	Index vertex_for_edge(Lookup& lookup,
// 		VertexList& vertices, Index first, Index second)
// 	{
// 		Lookup::key_type key(first, second);
// 		if (key.first > key.second)
// 			std::swap(key.first, key.second);
// 
// 		auto inserted = lookup.insert({ key, vertices.size() });
// 		if (inserted.second)
// 		{
// 			auto& edge0 = vertices[first];
// 			auto& edge1 = vertices[second];
// 			auto point = normalize(edge0 + edge1);
// 			vertices.push_back(point);
// 		}
// 
// 		return inserted.first->second;
// 	}

	void ClearMeshData();

public:	


};
