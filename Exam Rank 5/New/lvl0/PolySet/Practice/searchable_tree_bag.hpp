#pragma once
#include <iostream>
#include "searchable_bag.hpp"
#include "TreeBag.hpp"

class searchable_tree_bag : public TreeBag, public searchable_bag{
    public:
        searchable_tree_bag();
        searchable_tree_bag(const searchable_tree_bag &other);
        searchable_tree_bag &operator=(const searchable_tree_bag &other);
        ~searchable_tree_bag();

        virtual bool has(int value)const;
};