// Copyright Soccertitan 2026


#include "Sort/CrimSortOrder.h"

UCrimSortOrder::UCrimSortOrder()
{
}

bool UCrimSortOrder::GetResult(const UObject* A, const UObject* B, const UObject* Context) const
{
	if (!A || !B)
	{
		if (A)
		{
			return true;
		}
		return false;
	}
	
	return DoesAComeFirst(A, B, Context);
}
