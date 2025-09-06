#include "searchable_array_bag.hpp"

#include <iostream>

searchable_array_bag::searchable_array_bag() : ArrayBag() {}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &other) : ArrayBag(other){}

searchable_array_bag::~searchable_array_bag(){}

searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &other){
    if (this != &other){
        ArrayBag::operator=(other);
    }
    return *this;
}

bool searchable_array_bag::has(int value)const{
    for (int i = 0; i < _size; i++){
        if(_data[i] == value){
            return true;
        }
    }
    return false;
}
