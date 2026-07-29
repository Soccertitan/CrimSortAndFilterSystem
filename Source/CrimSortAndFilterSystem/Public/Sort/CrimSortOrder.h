// Copyright Soccertitan 2026

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CrimSortOrder.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable, DefaultToInstanced, EditInlineNew)
class CRIMSORTANDFILTERSYSTEM_API UCrimSortOrder : public UObject
{
	GENERATED_BODY()
	
public:
	UCrimSortOrder();
	
	/** Returns true if A comes before B. */
	bool GetResult(const UObject* A, const UObject* B, const UObject* Context) const;

protected:
	/** Return true if A comes before B. A and B are guaranteed to be valid. */
	UFUNCTION(BlueprintNativeEvent)
	bool DoesAComeFirst(const UObject* A, const UObject* B, const UObject* Context) const;
	virtual bool DoesAComeFirst_Implementation(const UObject* A, const UObject* B, const UObject* Context) const { return false; }
};
