// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HSG_HSGGameModeBase_generated_h
#error "HSGGameModeBase.generated.h already included, missing '#pragma once' in HSGGameModeBase.h"
#endif
#define HSG_HSGGameModeBase_generated_h

#define HSG_Source_HSG_HSGGameModeBase_h_16_RPC_WRAPPERS
#define HSG_Source_HSG_HSGGameModeBase_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define HSG_Source_HSG_HSGGameModeBase_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHSGGameModeBase(); \
	friend struct Z_Construct_UClass_AHSGGameModeBase_Statics; \
public: \
	DECLARE_CLASS(AHSGGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/HSG"), NO_API) \
	DECLARE_SERIALIZER(AHSGGameModeBase)


#define HSG_Source_HSG_HSGGameModeBase_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAHSGGameModeBase(); \
	friend struct Z_Construct_UClass_AHSGGameModeBase_Statics; \
public: \
	DECLARE_CLASS(AHSGGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/HSG"), NO_API) \
	DECLARE_SERIALIZER(AHSGGameModeBase)


#define HSG_Source_HSG_HSGGameModeBase_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AHSGGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AHSGGameModeBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHSGGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHSGGameModeBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHSGGameModeBase(AHSGGameModeBase&&); \
	NO_API AHSGGameModeBase(const AHSGGameModeBase&); \
public:


#define HSG_Source_HSG_HSGGameModeBase_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AHSGGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHSGGameModeBase(AHSGGameModeBase&&); \
	NO_API AHSGGameModeBase(const AHSGGameModeBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHSGGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHSGGameModeBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AHSGGameModeBase)


#define HSG_Source_HSG_HSGGameModeBase_h_16_PRIVATE_PROPERTY_OFFSET
#define HSG_Source_HSG_HSGGameModeBase_h_13_PROLOG
#define HSG_Source_HSG_HSGGameModeBase_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HSG_Source_HSG_HSGGameModeBase_h_16_PRIVATE_PROPERTY_OFFSET \
	HSG_Source_HSG_HSGGameModeBase_h_16_RPC_WRAPPERS \
	HSG_Source_HSG_HSGGameModeBase_h_16_INCLASS \
	HSG_Source_HSG_HSGGameModeBase_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HSG_Source_HSG_HSGGameModeBase_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HSG_Source_HSG_HSGGameModeBase_h_16_PRIVATE_PROPERTY_OFFSET \
	HSG_Source_HSG_HSGGameModeBase_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	HSG_Source_HSG_HSGGameModeBase_h_16_INCLASS_NO_PURE_DECLS \
	HSG_Source_HSG_HSGGameModeBase_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HSG_API UClass* StaticClass<class AHSGGameModeBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HSG_Source_HSG_HSGGameModeBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
