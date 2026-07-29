// Copyright Soccertitan 2026

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CrimSortOrderPreset.generated.h"

class UCrimSortOrder;

/**
 * 
 */
UCLASS()
class CRIMSORTANDFILTERSYSTEM_API UCrimSortOrderPreset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	// Can be shown in the UI for the type of sort this preset is.
	UPROPERTY(EditAnywhere)
	FText DisplayText;
	
	// The sorters to evaluate.
	UPROPERTY(EditAnywhere)
	TArray<TObjectPtr<UCrimSortOrder>> SortOrders;
};
