// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HSG_Planet_generated_h
#error "Planet.generated.h already included, missing '#pragma once' in Planet.h"
#endif
#define HSG_Planet_generated_h

#define HSG_Source_HSG_Planet_h_53_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMesh_Statics; \
	HSG_API static class UScriptStruct* StaticStruct();


template<> HSG_API UScriptStruct* StaticStruct<struct FMesh>();

#define HSG_Source_HSG_Planet_h_23_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FTriangle_Statics; \
	HSG_API static class UScriptStruct* StaticStruct();


template<> HSG_API UScriptStruct* StaticStruct<struct FTriangle>();

#define HSG_Source_HSG_Planet_h_136_RPC_WRAPPERS
#define HSG_Source_HSG_Planet_h_136_RPC_WRAPPERS_NO_PURE_DECLS
#define HSG_Source_HSG_Planet_h_136_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlanet(); \
	friend struct Z_Construct_UClass_APlanet_Statics; \
public: \
	DECLARE_CLASS(APlanet, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HSG"), NO_API) \
	DECLARE_SERIALIZER(APlanet)


#define HSG_Source_HSG_Planet_h_136_INCLASS \
private: \
	static void StaticRegisterNativesAPlanet(); \
	friend struct Z_Construct_UClass_APlanet_Statics; \
public: \
	DECLARE_CLASS(APlanet, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HSG"), NO_API) \
	DECLARE_SERIALIZER(APlanet)


#define HSG_Source_HSG_Planet_h_136_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlanet(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlanet) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlanet); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlanet); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlanet(APlanet&&); \
	NO_API APlanet(const APlanet&); \
public:


#define HSG_Source_HSG_Planet_h_136_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlanet(APlanet&&); \
	NO_API APlanet(const APlanet&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlanet); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlanet); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlanet)


#define HSG_Source_HSG_Planet_h_136_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CustomMesh() { return STRUCT_OFFSET(APlanet, CustomMesh); } \
	FORCEINLINE static uint32 __PPO__vertices() { return STRUCT_OFFSET(APlanet, vertices); } \
	FORCEINLINE static uint32 __PPO__normals() { return STRUCT_OFFSET(APlanet, normals); } \
	FORCEINLINE static uint32 __PPO__triangles() { return STRUCT_OFFSET(APlanet, triangles); } \
	FORCEINLINE static uint32 __PPO__uvs() { return STRUCT_OFFSET(APlanet, uvs); } \
	FORCEINLINE static uint32 __PPO__vertexColors() { return STRUCT_OFFSET(APlanet, vertexColors); } \
	FORCEINLINE static uint32 __PPO__tangents() { return STRUCT_OFFSET(APlanet, tangents); } \
	FORCEINLINE static uint32 __PPO__material() { return STRUCT_OFFSET(APlanet, material); } \
	FORCEINLINE static uint32 __PPO__mesh() { return STRUCT_OFFSET(APlanet, mesh); }


#define HSG_Source_HSG_Planet_h_133_PROLOG
#define HSG_Source_HSG_Planet_h_136_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HSG_Source_HSG_Planet_h_136_PRIVATE_PROPERTY_OFFSET \
	HSG_Source_HSG_Planet_h_136_RPC_WRAPPERS \
	HSG_Source_HSG_Planet_h_136_INCLASS \
	HSG_Source_HSG_Planet_h_136_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HSG_Source_HSG_Planet_h_136_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HSG_Source_HSG_Planet_h_136_PRIVATE_PROPERTY_OFFSET \
	HSG_Source_HSG_Planet_h_136_RPC_WRAPPERS_NO_PURE_DECLS \
	HSG_Source_HSG_Planet_h_136_INCLASS_NO_PURE_DECLS \
	HSG_Source_HSG_Planet_h_136_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HSG_API UClass* StaticClass<class APlanet>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HSG_Source_HSG_Planet_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
