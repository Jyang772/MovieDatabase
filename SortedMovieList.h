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

    bool add(const ListItemType& newItem); //For adding from file AND user input

    int find(string name);                //Finds a movie in database, returns an index


    bool remove(int index);               //Deletes movie from database
    void retrieve(int index, ListItemType& item);         //Retrieves item at index, returns it by reference in return

    //Miscellaneous.
    bool findRelated(string name);
    int binarySearch(string name);

private:
    ListItemType items[MAX_LIST];
    int size;
};

#endif // SORTEDMOVIELIST_H
