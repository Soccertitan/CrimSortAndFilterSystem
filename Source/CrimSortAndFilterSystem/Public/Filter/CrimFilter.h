// Copyright Soccertitan 2026

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CrimFilter.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable, DefaultToInstanced, EditInlineNew)
class CRIMSORTANDFILTERSYSTEM_API UCrimFilter : public UObject
{
	GENERATED_BODY()
	
public:
	UCrimFilter();

	/**
	 * Returns true if the object should be filtered out.
	 * @param Object The object to evaluate.
	 * @param Context A context that can contain information for the filter to evaluate the object.
	 */
	UFUNCTION(BlueprintNativeEvent)
	bool ShouldFilterObject(const UObject* Object, const UObject* Context = nullptr) const;
	virtual bool ShouldFilterObject_Implementation(const UObject* Object, const UObject* Context) const { return false; }
};
