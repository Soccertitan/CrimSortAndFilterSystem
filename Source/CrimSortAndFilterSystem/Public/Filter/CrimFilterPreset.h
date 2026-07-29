// Copyright Soccertitan 2026

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CrimFilterPreset.generated.h"

class UCrimFilter;

/**
 * 
 */
UCLASS()
class CRIMSORTANDFILTERSYSTEM_API UCrimFilterPreset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	// Can be shown in the UI for the type of filter this preset is.
	UPROPERTY(EditAnywhere)
	FText DisplayText;
	
	// The filters to evaluate.
	UPROPERTY(EditAnywhere)
	TArray<TObjectPtr<UCrimFilter>> Filters;
};
