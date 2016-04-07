/*
 * Copyright (c) 2008-2015, NVIDIA CORPORATION.  All rights reserved.
 *
 * NVIDIA CORPORATION and its licensors retain all intellectual property
 * and proprietary rights in and to this software, related documentation
 * and any modifications thereto.  Any use, reproduction, disclosure or
 * distribution of this software and related documentation without an express
 * license agreement from NVIDIA CORPORATION is strictly prohibited.
 */


// This file was generated by NxParameterized/scripts/GenParameterized.pl
// Created: 2015.06.02 04:12:11

#include "ClothingMaterialLibraryParameters_0p0.h"
#include <string.h>
#include <stdlib.h>

using namespace NxParameterized;

namespace physx
{
namespace apex
{

using namespace ClothingMaterialLibraryParameters_0p0NS;

const char* const ClothingMaterialLibraryParameters_0p0Factory::vptr =
    NxParameterized::getVptr<ClothingMaterialLibraryParameters_0p0, ClothingMaterialLibraryParameters_0p0::ClassAlignment>();

const physx::PxU32 NumParamDefs = 15;
static NxParameterized::DefinitionImpl* ParamDefTable; // now allocated in buildTree [NumParamDefs];


static const size_t ParamLookupChildrenTable[] =
{
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
};

#define TENUM(type) physx::##type
#define CHILDREN(index) &ParamLookupChildrenTable[index]
static const NxParameterized::ParamLookupNode ParamLookupTable[NumParamDefs] =
{
	{ TYPE_STRUCT, false, 0, CHILDREN(0), 1 },
	{ TYPE_ARRAY, true, (size_t)(&((ParametersStruct*)0)->materials), CHILDREN(1), 1 }, // materials
	{ TYPE_STRUCT, false, 1 * sizeof(ClothingMaterial_Type), CHILDREN(2), 12 }, // materials[]
	{ TYPE_STRING, false, (size_t)(&((ClothingMaterial_Type*)0)->materialName), NULL, 0 }, // materials[].materialName
	{ TYPE_F32, false, (size_t)(&((ClothingMaterial_Type*)0)->stretchingStiffness), NULL, 0 }, // materials[].stretchingStiffness
	{ TYPE_F32, false, (size_t)(&((ClothingMaterial_Type*)0)->bendingStiffness), NULL, 0 }, // materials[].bendingStiffness
	{ TYPE_BOOL, false, (size_t)(&((ClothingMaterial_Type*)0)->orthoBending), NULL, 0 }, // materials[].orthoBending
	{ TYPE_F32, false, (size_t)(&((ClothingMaterial_Type*)0)->damping), NULL, 0 }, // materials[].damping
	{ TYPE_BOOL, false, (size_t)(&((ClothingMaterial_Type*)0)->comDamping), NULL, 0 }, // materials[].comDamping
	{ TYPE_F32, false, (size_t)(&((ClothingMaterial_Type*)0)->friction), NULL, 0 }, // materials[].friction
	{ TYPE_U32, false, (size_t)(&((ClothingMaterial_Type*)0)->solverIterations), NULL, 0 }, // materials[].solverIterations
	{ TYPE_F32, false, (size_t)(&((ClothingMaterial_Type*)0)->gravityScale), NULL, 0 }, // materials[].gravityScale
	{ TYPE_F32, false, (size_t)(&((ClothingMaterial_Type*)0)->hardStretchLimitation), NULL, 0 }, // materials[].hardStretchLimitation
	{ TYPE_F32, false, (size_t)(&((ClothingMaterial_Type*)0)->maxDistanceBias), NULL, 0 }, // materials[].maxDistanceBias
	{ TYPE_U32, false, (size_t)(&((ClothingMaterial_Type*)0)->hierarchicalSolverIterations), NULL, 0 }, // materials[].hierarchicalSolverIterations
};


bool ClothingMaterialLibraryParameters_0p0::mBuiltFlag = false;
NxParameterized::MutexType ClothingMaterialLibraryParameters_0p0::mBuiltFlagMutex;

ClothingMaterialLibraryParameters_0p0::ClothingMaterialLibraryParameters_0p0(NxParameterized::Traits* traits, void* buf, PxI32* refCount) :
	NxParameters(traits, buf, refCount)
{
	//mParameterizedTraits->registerFactory(className(), &ClothingMaterialLibraryParameters_0p0FactoryInst);

	if (!buf) //Do not init data if it is inplace-deserialized
	{
		initDynamicArrays();
		initStrings();
		initReferences();
		initDefaults();
	}
}

ClothingMaterialLibraryParameters_0p0::~ClothingMaterialLibraryParameters_0p0()
{
	freeStrings();
	freeReferences();
	freeDynamicArrays();
}

void ClothingMaterialLibraryParameters_0p0::destroy()
{
	// We cache these fields here to avoid overwrite in destructor
	bool doDeallocateSelf = mDoDeallocateSelf;
	NxParameterized::Traits* traits = mParameterizedTraits;
	physx::PxI32* refCount = mRefCount;
	void* buf = mBuffer;

	this->~ClothingMaterialLibraryParameters_0p0();

	NxParameters::destroy(this, traits, doDeallocateSelf, refCount, buf);
}

const NxParameterized::DefinitionImpl* ClothingMaterialLibraryParameters_0p0::getParameterDefinitionTree(void)
{
	if (!mBuiltFlag) // Double-checked lock
	{
		NxParameterized::MutexType::ScopedLock lock(mBuiltFlagMutex);
		if (!mBuiltFlag)
		{
			buildTree();
		}
	}

	return(&ParamDefTable[0]);
}

const NxParameterized::DefinitionImpl* ClothingMaterialLibraryParameters_0p0::getParameterDefinitionTree(void) const
{
	ClothingMaterialLibraryParameters_0p0* tmpParam = const_cast<ClothingMaterialLibraryParameters_0p0*>(this);

	if (!mBuiltFlag) // Double-checked lock
	{
		NxParameterized::MutexType::ScopedLock lock(mBuiltFlagMutex);
		if (!mBuiltFlag)
		{
			tmpParam->buildTree();
		}
	}

	return(&ParamDefTable[0]);
}

NxParameterized::ErrorType ClothingMaterialLibraryParameters_0p0::getParameterHandle(const char* long_name, Handle& handle) const
{
	ErrorType Ret = NxParameters::getParameterHandle(long_name, handle);
	if (Ret != ERROR_NONE)
	{
		return(Ret);
	}

	size_t offset;
	void* ptr;

	getVarPtr(handle, ptr, offset);

	if (ptr == NULL)
	{
		return(ERROR_INDEX_OUT_OF_RANGE);
	}

	return(ERROR_NONE);
}

NxParameterized::ErrorType ClothingMaterialLibraryParameters_0p0::getParameterHandle(const char* long_name, Handle& handle)
{
	ErrorType Ret = NxParameters::getParameterHandle(long_name, handle);
	if (Ret != ERROR_NONE)
	{
		return(Ret);
	}

	size_t offset;
	void* ptr;

	getVarPtr(handle, ptr, offset);

	if (ptr == NULL)
	{
		return(ERROR_INDEX_OUT_OF_RANGE);
	}

	return(ERROR_NONE);
}

void ClothingMaterialLibraryParameters_0p0::getVarPtr(const Handle& handle, void*& ptr, size_t& offset) const
{
	ptr = getVarPtrHelper(&ParamLookupTable[0], const_cast<ClothingMaterialLibraryParameters_0p0::ParametersStruct*>(&parameters()), handle, offset);
}


/* Dynamic Handle Indices */
/* [1,0] - materials.materialName */

void ClothingMaterialLibraryParameters_0p0::freeParameterDefinitionTable(NxParameterized::Traits* traits)
{
	if (!traits)
	{
		return;
	}

	if (!mBuiltFlag) // Double-checked lock
	{
		return;
	}

	NxParameterized::MutexType::ScopedLock lock(mBuiltFlagMutex);

	if (!mBuiltFlag)
	{
		return;
	}

	for (physx::PxU32 i = 0; i < NumParamDefs; ++i)
	{
		ParamDefTable[i].~DefinitionImpl();
	}

	traits->free(ParamDefTable);

	mBuiltFlag = false;
}

#define PDEF_PTR(index) (&ParamDefTable[index])

void ClothingMaterialLibraryParameters_0p0::buildTree(void)
{

	physx::PxU32 allocSize = sizeof(NxParameterized::DefinitionImpl) * NumParamDefs;
	ParamDefTable = (NxParameterized::DefinitionImpl*)(mParameterizedTraits->alloc(allocSize));
	memset(static_cast<void*>(ParamDefTable), 0, allocSize);

	for (physx::PxU32 i = 0; i < NumParamDefs; ++i)
	{
		NX_PARAM_PLACEMENT_NEW(ParamDefTable + i, NxParameterized::DefinitionImpl)(*mParameterizedTraits);
	}

	// Initialize DefinitionImpl node: nodeIndex=0, longName=""
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[0];
		ParamDef->init("", TYPE_STRUCT, "STRUCT", true);






	}

	// Initialize DefinitionImpl node: nodeIndex=1, longName="materials"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[1];
		ParamDef->init("materials", TYPE_ARRAY, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Array of materials that are part of this library.", true);
		ParamDefTable[1].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */




		ParamDef->setArraySize(-1);
		static const physx::PxU8 dynHandleIndices[2] = { 1, 0, };
		ParamDef->setDynamicHandleIndicesMap(dynHandleIndices, 2);

	}

	// Initialize DefinitionImpl node: nodeIndex=2, longName="materials[]"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[2];
		ParamDef->init("materials", TYPE_STRUCT, "ClothingMaterial", true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Array of materials that are part of this library.", true);
		ParamDefTable[2].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=3, longName="materials[].materialName"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[3];
		ParamDef->init("materialName", TYPE_STRING, NULL, true);






	}

	// Initialize DefinitionImpl node: nodeIndex=4, longName="materials[].stretchingStiffness"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[4];
		ParamDef->init("stretchingStiffness", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("max", physx::PxF64(1.0), true);
		HintTable[1].init("min", physx::PxF64(0.0), true);
		ParamDefTable[4].setHints((const NxParameterized::Hint**)HintPtrTable, 2);

#else

		static HintImpl HintTable[3];
		static Hint* HintPtrTable[3] = { &HintTable[0], &HintTable[1], &HintTable[2], };
		HintTable[0].init("max", physx::PxF64(1.0), true);
		HintTable[1].init("min", physx::PxF64(0.0), true);
		HintTable[2].init("shortDescription", "Stretching stiffness of the cloth in the range (0, 1].", true);
		ParamDefTable[4].setHints((const NxParameterized::Hint**)HintPtrTable, 3);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=5, longName="materials[].bendingStiffness"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[5];
		ParamDef->init("bendingStiffness", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("max", physx::PxF64(1.0), true);
		HintTable[1].init("min", physx::PxF64(0.0), true);
		ParamDefTable[5].setHints((const NxParameterized::Hint**)HintPtrTable, 2);

#else

		static HintImpl HintTable[3];
		static Hint* HintPtrTable[3] = { &HintTable[0], &HintTable[1], &HintTable[2], };
		HintTable[0].init("max", physx::PxF64(1.0), true);
		HintTable[1].init("min", physx::PxF64(0.0), true);
		HintTable[2].init("shortDescription", "Bending stiffness of the cloth in the range [0, 1].", true);
		ParamDefTable[5].setHints((const NxParameterized::Hint**)HintPtrTable, 3);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=6, longName="materials[].orthoBending"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[6];
		ParamDef->init("orthoBending", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("longDescription", "Bending is modeled via an angular spring between adjacent triangles. This mode is slower but independent of stretching resistance.\n", true);
		HintTable[1].init("shortDescription", "Enable/disable orthogonal bending resistance.", true);
		ParamDefTable[6].setHints((const NxParameterized::Hint**)HintPtrTable, 2);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=7, longName="materials[].damping"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[7];
		ParamDef->init("damping", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("max", physx::PxF64(1.0), true);
		HintTable[1].init("min", physx::PxF64(0.0), true);
		ParamDefTable[7].setHints((const NxParameterized::Hint**)HintPtrTable, 2);

#else

		static HintImpl HintTable[3];
		static Hint* HintPtrTable[3] = { &HintTable[0], &HintTable[1], &HintTable[2], };
		HintTable[0].init("max", physx::PxF64(1.0), true);
		HintTable[1].init("min", physx::PxF64(0.0), true);
		HintTable[2].init("shortDescription", "Spring damping of the cloth in the range [0, 1]", true);
		ParamDefTable[7].setHints((const NxParameterized::Hint**)HintPtrTable, 3);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=8, longName="materials[].comDamping"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[8];
		ParamDef->init("comDamping", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("longDescription", "If set, the global rigid body modes (translation and rotation) are extracted from damping. This way, the cloth\ncan freely move and rotate even under high damping.\n", true);
		HintTable[1].init("shortDescription", "Enable/disable center of mass damping of internal velocities.", true);
		ParamDefTable[8].setHints((const NxParameterized::Hint**)HintPtrTable, 2);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=9, longName="materials[].friction"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[9];
		ParamDef->init("friction", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("max", physx::PxF64(1.0), true);
		HintTable[1].init("min", physx::PxF64(0.0), true);
		ParamDefTable[9].setHints((const NxParameterized::Hint**)HintPtrTable, 2);

#else

		static HintImpl HintTable[3];
		static Hint* HintPtrTable[3] = { &HintTable[0], &HintTable[1], &HintTable[2], };
		HintTable[0].init("max", physx::PxF64(1.0), true);
		HintTable[1].init("min", physx::PxF64(0.0), true);
		HintTable[2].init("shortDescription", "Friction coefficient in the range [0, 1]", true);
		ParamDefTable[9].setHints((const NxParameterized::Hint**)HintPtrTable, 3);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=10, longName="materials[].solverIterations"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[10];
		ParamDef->init("solverIterations", TYPE_U32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("min", physx::PxU64(1), true);
		ParamDefTable[10].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#else

		static HintImpl HintTable[3];
		static Hint* HintPtrTable[3] = { &HintTable[0], &HintTable[1], &HintTable[2], };
		HintTable[0].init("longDescription", "Small numbers make the simulation faster while the cloth gets less stiff.\n", true);
		HintTable[1].init("min", physx::PxU64(1), true);
		HintTable[2].init("shortDescription", "Number of solver iterations.", true);
		ParamDefTable[10].setHints((const NxParameterized::Hint**)HintPtrTable, 3);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=11, longName="materials[].gravityScale"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[11];
		ParamDef->init("gravityScale", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("longDescription", "A value of 0 will make the cloth ignore gravity, a value of 10 will apply 10 times the gravity.\n", true);
		HintTable[1].init("shortDescription", "Amount of gravity that is applied to the cloth.", true);
		ParamDefTable[11].setHints((const NxParameterized::Hint**)HintPtrTable, 2);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=12, longName="materials[].hardStretchLimitation"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[12];
		ParamDef->init("hardStretchLimitation", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("max", physx::PxF64(2.0), true);
		HintTable[1].init("min", physx::PxF64(0.0), true);
		ParamDefTable[12].setHints((const NxParameterized::Hint**)HintPtrTable, 2);

#else

		static HintImpl HintTable[4];
		static Hint* HintPtrTable[4] = { &HintTable[0], &HintTable[1], &HintTable[2], &HintTable[3], };
		HintTable[0].init("longDescription", "Good values are usually between 1 and 1.1. Any value >= 1 will guarantee that a certain set of edges is not longer\nthan that value times the initial rest length.\n", true);
		HintTable[1].init("max", physx::PxF64(2.0), true);
		HintTable[2].init("min", physx::PxF64(0.0), true);
		HintTable[3].init("shortDescription", "Make cloth simulation less stretchy. A value smaller than 1 will turn it off.", true);
		ParamDefTable[12].setHints((const NxParameterized::Hint**)HintPtrTable, 4);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=13, longName="materials[].maxDistanceBias"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[13];
		ParamDef->init("maxDistanceBias", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("max", physx::PxF64(1.0), true);
		HintTable[1].init("min", physx::PxF64(-1.0), true);
		ParamDefTable[13].setHints((const NxParameterized::Hint**)HintPtrTable, 2);

#else

		static HintImpl HintTable[4];
		static Hint* HintPtrTable[4] = { &HintTable[0], &HintTable[1], &HintTable[2], &HintTable[3], };
		HintTable[0].init("longDescription", "A value smaller than 0 will turn the sphere into a capsule and eventually a line (at value -1) along the normal of the vertex.\nA value bigger than 0 will turn the sphere into a disc.\n", true);
		HintTable[1].init("max", physx::PxF64(1.0), true);
		HintTable[2].init("min", physx::PxF64(-1.0), true);
		HintTable[3].init("shortDescription", "Deform the max distance sphere into a capsule or a disc.", true);
		ParamDefTable[13].setHints((const NxParameterized::Hint**)HintPtrTable, 4);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=14, longName="materials[].hierarchicalSolverIterations"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[14];
		ParamDef->init("hierarchicalSolverIterations", TYPE_U32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("min", physx::PxU64(0), true);
		ParamDefTable[14].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#else

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("min", physx::PxU64(0), true);
		HintTable[1].init("shortDescription", "Number of iterations of the hierarchical cloth solver.", true);
		ParamDefTable[14].setHints((const NxParameterized::Hint**)HintPtrTable, 2);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// SetChildren for: nodeIndex=0, longName=""
	{
		static Definition* Children[1];
		Children[0] = PDEF_PTR(1);

		ParamDefTable[0].setChildren(Children, 1);
	}

	// SetChildren for: nodeIndex=1, longName="materials"
	{
		static Definition* Children[1];
		Children[0] = PDEF_PTR(2);

		ParamDefTable[1].setChildren(Children, 1);
	}

	// SetChildren for: nodeIndex=2, longName="materials[]"
	{
		static Definition* Children[12];
		Children[0] = PDEF_PTR(3);
		Children[1] = PDEF_PTR(4);
		Children[2] = PDEF_PTR(5);
		Children[3] = PDEF_PTR(6);
		Children[4] = PDEF_PTR(7);
		Children[5] = PDEF_PTR(8);
		Children[6] = PDEF_PTR(9);
		Children[7] = PDEF_PTR(10);
		Children[8] = PDEF_PTR(11);
		Children[9] = PDEF_PTR(12);
		Children[10] = PDEF_PTR(13);
		Children[11] = PDEF_PTR(14);

		ParamDefTable[2].setChildren(Children, 12);
	}

	mBuiltFlag = true;

}
void ClothingMaterialLibraryParameters_0p0::initStrings(void)
{
}

void ClothingMaterialLibraryParameters_0p0::initDynamicArrays(void)
{
	materials.buf = NULL;
	materials.isAllocated = true;
	materials.elementSize = sizeof(ClothingMaterial_Type);
	materials.arraySizes[0] = 0;
}

void ClothingMaterialLibraryParameters_0p0::initDefaults(void)
{

	freeStrings();
	freeReferences();
	freeDynamicArrays();

	initDynamicArrays();
	initStrings();
	initReferences();
}

void ClothingMaterialLibraryParameters_0p0::initReferences(void)
{
}

void ClothingMaterialLibraryParameters_0p0::freeDynamicArrays(void)
{
	if (materials.isAllocated && materials.buf)
	{
		mParameterizedTraits->free(materials.buf);
	}
}

void ClothingMaterialLibraryParameters_0p0::freeStrings(void)
{

	for (int i = 0; i < materials.arraySizes[0]; ++i)
	{
		if (materials.buf[i].materialName.isAllocated && materials.buf[i].materialName.buf)
		{
			mParameterizedTraits->strfree((char*)materials.buf[i].materialName.buf);
		}
	}
}

void ClothingMaterialLibraryParameters_0p0::freeReferences(void)
{
}

} // namespace apex
} // namespace physx
