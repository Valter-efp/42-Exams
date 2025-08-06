#pragma once

#include "Bag.hpp"

class searchable_bag : virtual public Bag
{
	public:
		virtual bool has(int) const = 0;
};