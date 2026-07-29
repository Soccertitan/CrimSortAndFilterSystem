// Copyright Soccertitan 2026


#include "CrimSortAndFilterStatics.h"

#include "Filter/CrimFilter.h"
#include "Filter/CrimFilterPreset.h"
#include "Sort/CrimSortOrder.h"
#include "Sort/CrimSortOrderPreset.h"

void UCrimSortAndFilterStatics::FilterObjects(TArray<UObject*>& Objects, const TArray<UCrimFilter*>& Filters, const UObject* Context)
{
	for (int32 Index = Objects.Num(); Index >= 0; --Index)
	{
		if (Objects[Index])
		{
			for (UCrimFilter* Filter : Filters)
			{
				if (Filter && Filter->ShouldFilterObject(Objects[Index], Context))
				{
					Objects.RemoveAt(Index);
					break;
				}
			}
		}
		else
		{
			Objects.RemoveAt(Index);
		}
	}
}

void UCrimSortAndFilterStatics::FilterObjectsByPreset(TArray<UObject*>& Objects, const UCrimFilterPreset* FilterPreset, const UObject* Context)
{
	if (FilterPreset)
	{
		FilterObjects(Objects, FilterPreset->Filters, Context);
	}
}

void UCrimSortAndFilterStatics::SortObjects(TArray<UObject*>& Objects, const TArray<UCrimSortOrder*>& SortOrders, const UObject* Context)
{
	Algo::Sort(Objects, [SortOrders, Context](const UObject* A, const UObject* B)
	{
		for (const UCrimSortOrder* SortOrder : SortOrders)
		{
			if (SortOrder)
			{
				if (SortOrder->GetResult(A, B, Context))
				{
					return true;
				}
			}
		}
		return false;
	});
}

void UCrimSortAndFilterStatics::SortObjectsByPreset(TArray<UObject*>& Objects, const UCrimSortOrderPreset* SortOrderPreset, const UObject* Context)
{
	if (SortOrderPreset)
	{
		SortObjects(Objects, SortOrderPreset->SortOrders, Context);
	}
}

void UCrimSortAndFilterStatics::StableSortObjects(TArray<UObject*>& Objects, const TArray<UCrimSortOrder*>& SortOrders, const UObject* Context)
{
	Algo::StableSort(Objects, [SortOrders, Context](const UObject* A, const UObject* B)
	{
		for (const UCrimSortOrder* SortOrder : SortOrders)
		{
			if (SortOrder)
			{
				if (SortOrder->GetResult(A, B, Context))
				{
					return true;
				}
			}
		}
		return false;
	});
}

void UCrimSortAndFilterStatics::StableSortObjectsByPreset(TArray<UObject*>& Objects, const UCrimSortOrderPreset* SortOrderPreset, const UObject* Context)
{
	if (SortOrderPreset)
	{
		StableSortObjects(Objects, SortOrderPreset->SortOrders, Context);
	}
}
