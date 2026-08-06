// Copyright Soccertitan 2026

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CrimSortAndFilterStatics.generated.h"

class UCrimSortOrderPreset;
class UCrimSortOrder;
class UCrimFilter;
class UCrimFilterPreset;
/**
 * 
 */
UCLASS()
class CRIMSORTANDFILTERSYSTEM_API UCrimSortAndFilterStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Filter", DisplayName = "Filter")
	static void FilterObjects(const TArray<UObject*>& Objects, TArray<UObject*>& FilteredObjects, const TArray<UCrimFilter*>& Filters, const UObject* Context = nullptr);
	
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Filter", DisplayName = "FilterPreset")
	static void FilterObjectsByPreset(const TArray<UObject*>& Objects, TArray<UObject*>& FilteredObjects, const UCrimFilterPreset* FilterPreset, const UObject* Context = nullptr);
	
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Sort", DisplayName = "Sort")
	static void SortObjects(UPARAM(ref) TArray<UObject*>& Objects, const TArray<UCrimSortOrder*>& SortOrders, const UObject* Context = nullptr);
	
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Sort", DisplayName = "SortPreset")
	static void SortObjectsByPreset(UPARAM(ref) TArray<UObject*>& Objects, const UCrimSortOrderPreset* SortOrderPreset, const UObject* Context = nullptr);
	
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Sort", DisplayName = "StableSort")
	static void StableSortObjects(UPARAM(ref) TArray<UObject*>& Objects, const TArray<UCrimSortOrder*>& SortOrders, const UObject* Context = nullptr);
	
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "Sort", DisplayName = "StableSortPreset")
	static void StableSortObjectsByPreset(UPARAM(ref) TArray<UObject*>& Objects, const UCrimSortOrderPreset* SortOrderPreset, const UObject* Context = nullptr);
};
