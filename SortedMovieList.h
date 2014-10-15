#ifndef SORTEDMOVIELIST_H
#define SORTEDMOVIELIST_H

#include "MovieType.h"
const int MAX_LIST = 20;
typedef MovieType ListItemType;

using namespace std;


//template<class ListItemType>


class SortedMovieList{
public:
    SortedMovieList();
    bool isEmpty() const;
    int getLength() const;
    bool insert(int index, ListItemType newItem);

    bool add();
    void add(const ListItemType& newItem); //For adding from file AND user input

    int find(string name);
    bool remove(string name);
    void retrieve(string name);

    void display();
    void display(ListItemType& dataItem);

private:
    ListItemType items[MAX_LIST];
    int size;
};

#endif // SORTEDMOVIELIST_H
