#include "set.hpp"

set::set(searchable_bag &other) : bag(other){}

set::~set(){}

bool set::has(int value)const{
	return(bag.has(value));
}

void set::insert(int value){
	if(!(this->bag.has(value)))
		bag.insert(value);
}

void set::insert(int *data, int size){
	for(int i = 0; i < size; i++)
		this->insert(data[i]);
}

void set::print()const{
	bag.print();
}

void set::clear(){
	bag.clear();
}

const searchable_bag &set::get_bag(){
	return this->bag;
}