#pragma once
#include <iostream>
#include "searchable_bag.hpp"

class set{
	private:
		searchable_bag &bag;
	public:
		set() = delete;
		set(const set &other) = delete;
		set &operator=(const set &other) = delete;
		set(searchable_bag &other);
		~set();

		bool has(int value)const;
		void insert(int);
		void insert(int *, int);
		void print()const;
		void clear();

		const searchable_bag &get_bag();
};