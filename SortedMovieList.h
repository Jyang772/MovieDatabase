#ifndef SORTEDMOVIELIST_H
#define SORTEDMOVIELIST_H

#include "MovieType.h"
const int MAX_LIST = 10;
typedef MovieType ListItemType;


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

private:
    ListItemType items[MAX_LIST];
    int size;
};

#endif // SORTEDMOVIELIST_H
