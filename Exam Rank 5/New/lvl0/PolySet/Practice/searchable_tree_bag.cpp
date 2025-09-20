#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : TreeBag(){}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other) : TreeBag(other){}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other){
    if(this != &other)
        TreeBag::operator=(other);
    return *this;
}

searchable_tree_bag::~searchable_tree_bag(){}

bool searchable_tree_bag::has(int value)const{
    Node *current = root;
    while(current){
        if(current->value == value){
            return true;
        } else if(current->value > value){
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}