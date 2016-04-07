// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EnvQueryTypes.h"
#include "EnvironmentQuery/EQSQueryResultSourceInterface.h"
#include "EnvQueryInstanceBlueprintWrapper.generated.h"

UCLASS(BlueprintType, meta = (DisplayName = "EQS Query Instance"))
class AIMODULE_API UEnvQueryInstanceBlueprintWrapper : public UObject, public IEQSQueryResultSourceInterface
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEQSQueryDoneSignature, UEnvQueryInstanceBlueprintWrapper*, QueryInstance, EEnvQueryStatus::Type, QueryStatus);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "EQS")
	int32 QueryID;

	EEnvQueryRunMode::Type RunMode;

	TSharedPtr<FEnvQueryResult> QueryResult;

	UPROPERTY(BlueprintReadOnly, Category = "EQS")
	TSubclassOf<UEnvQueryItemType> ItemType;

	/** index of query option, that generated items */
	UPROPERTY(BlueprintReadOnly, Category = "EQS")
	int32 OptionIndex;
	
	UPROPERTY(BlueprintAssignable, Category = "AI|EQS", meta = (DisplayName = "OnQueryFinished"))
	FEQSQueryDoneSignature OnQueryFinishedEvent;

public:
	UEnvQueryInstanceBlueprintWrapper(const FObjectInitializer& ObjectInitializer);

	void OnQueryFinished(TSharedPtr<FEnvQueryResult> Result);

	void SetRunMode(EEnvQueryRunMode::Type InRunMode) { RunMode = InRunMode; }
	void SetQueryID(int32 InQueryID) { QueryID = InQueryID; }

	UFUNCTION(BlueprintPure, Category = "AI|EQS")
	float GetItemScore(int32 ItemIndex);

	/** return an array filled with resulting actors. Not that it makes sense only if ItemType is a EnvQueryItemType_ActorBase-derived type */
	UFUNCTION(BlueprintPure, Category = "AI|EQS")
	TArray<AActor*> GetResultsAsActors();

	/** returns an array of locations generated by the query. If the query generated Actors the the array is filled with their locations */
	UFUNCTION(BlueprintPure, Category = "AI|EQS")
	TArray<FVector> GetResultsAsLocations();
};