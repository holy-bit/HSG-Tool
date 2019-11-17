// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
//#include "Math/UnrealMathUtility.h"
//#include <map>
#include "Planet.generated.h"
DECLARE_LOG_CATEGORY_EXTERN(LogMyGame, Log, All);

//using namespace std;


//typedef  TArray<FMeshTrianglew> TriangleList;
//typedef  TArray<FVector> VertexList;


USTRUCT()
struct FTriangle
{
	GENERATED_BODY()
public:
	UPROPERTY()
		int32 X;
	UPROPERTY()
		int32 Y;
	UPROPERTY()
		int32 Z;

	UPROPERTY()
		int32 Vertex[3];

	FTriangle(){}
	FTriangle(int32& X, int32& Y, int32& Z)
	{
		X = X;
		Y = Y;
		Z = Z;

		Vertex[0] = X;
		Vertex[1] = Y;
		Vertex[2] = Z;

	}
};


USTRUCT()
struct FMesh
{
	GENERATED_BODY()
public:
	UPROPERTY()
		TArray<FVector> vertices;
	UPROPERTY()
		TArray<FVector> normals;
	UPROPERTY()
		TArray<FVector2D> uvs;
	UPROPERTY()
		TArray<FLinearColor> vertexColors;
	UPROPERTY()
		TArray<FProcMeshTangent> tangents;

	UPROPERTY()
		TArray<FTriangle> triangles;

	UPROPERTY()
		TArray<int32> index;


	void AddTriangle(int32 V1, int32 V2, int32 V3)
	{
		triangles.Add(FTriangle(V1,V2,V3));
		index.Add(V1);
		index.Add(V2);
		index.Add(V3);

	}

	FMesh() {}
	FMesh(TArray<FVector>& vertices_P)
	{
		vertices = vertices_P;
	}
	
};


namespace icosahedron
{
	const float Z = 50;//.850650808352039932f;
	const float X = (1 + sqrt(5)) / 2 * 50;//.525731112119133606f;
	const float N = 0.f;

	static TArray<FVector> vertices =
	{
	  {-Z,X,N}, {Z,X,N}, {-Z,-X,N}, {Z,-X,N},
	  {N,-Z,X}, {N,Z,X}, {N,-Z,-X}, {N,Z,-X},
	  {X,N,-Z}, {X,N,Z}, {-X,N,-Z}, {-X,N,Z}
	};

	static TArray<FVector> triangles =
	{
	  {0,11,5},{0,5,1},{0,1,7},{0,7,10},{0,10,11},
	  {1,5,9},{5,11,4},{11,10,2},{10,7,6},{7,1,8},
	  {3,9,4},{3,4,2},{3,2,6},{3,6,8},{3,8,9},
	  {4,9,5},{2,4,11},{6,2,10},{8,6,7},{9,8,1}
	};

// 	static TArray<FVector> vertices =
// 	{
// 	  {-X,N,Z}, {X,N,Z}, {-X,N,-Z}, {X,N,-Z},
// 	  {N,Z,X}, {N,Z,-X}, {N,-Z,X}, {N,-Z,-X},
// 	  {Z,X,N}, {-Z,X, N}, {Z,-X,N}, {-Z,-X, N}
// 	};
// 
// 	static TArray<FVector> triangles =
// 	{
// 	  {0,4,1},{0,9,4},{9,5,4},{4,5,8},{4,8,1},
// 	  {8,10,1},{8,3,10},{5,3,8},{5,2,3},{2,7,3},
// 	  {7,10,3},{7,6,10},{7,11,6},{11,0,6},{0,1,6},
// 	  {6,1,10},{9,0,11},{9,11,2},{9,2,5},{7,2,11}
// 	};
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural Parameters")
		UMaterialInterface* material;

	UPROPERTY()
		FMesh mesh;
	/* Creates a triangle that connects the given vertices */
	void AddTriangle(int32 V1, int32 V2, int32 V3);
	virtual void OnConstruction(const FTransform& Transform) override;

	FVector getMiddle(FVector& v1, FVector& v2);

	void subdivideIcosahedron();

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
