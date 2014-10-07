#ifndef SORTEDMOVIELIST_H
#define SORTEDMOVIELIST_H

#include "MovieType.h"
const int MAX_LIST = 20;
//typedef MovieType ListItemType;


template<class ListItemType>
class SortedMovieList{
public:
    SortedMovieList();
    bool isEmpty() const;
    int getLength() const;
    bool insert(int index, ListItemType newItem);
    bool add(const ListItemType& newItem);
    bool remove(int index);
    bool retrieve(int index, ListItemType& dataItem) const;
    void display() const;

    void remove(string name);
    void retrieve(string name) const;
    void display(const ListItemType& dataItem) const;

private:
    ListItemType items[MAX_LIST];
    int size;
};

#endif // SORTEDMOVIELIST_H
