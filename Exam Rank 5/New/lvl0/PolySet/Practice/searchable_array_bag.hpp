#pragma once

#include <iostream>
#include "ArrayBag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public ArrayBag, public searchable_bag{
    public:
        searchable_array_bag();
        searchable_array_bag(const searchable_array_bag &other);
        searchable_array_bag &operator=(const searchable_array_bag &other);
        ~searchable_array_bag();

        virtual bool has(int value)const;
};