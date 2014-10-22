#ifndef SORTEDMOVIELIST_H
#define SORTEDMOVIELIST_H

#include "MovieType.h"
#include <stack>
const int MAX_LIST = 20;
typedef MovieType ListItemType;

using namespace std;


//template<class ListItemType>


class SortedMovieList{
public:
    SortedMovieList();
    ~SortedMovieList();
    bool isEmpty() const;
    int getLength() const;

    bool insert(int index, ListItemType newItem);
    bool add(const ListItemType& newItem); //For adding from file AND user input
    int find(string name);                //Finds a movie in database, returns an index
    bool remove(int index);               //Deletes movie from database
    void retrieve(int index, ListItemType& item);         //Retrieves item at index, returns it by reference in return



    //Miscellaneous.
    bool findWithStar(int index, string& star);
    bool findRelated(string name);
    int binarySearch(string name);

    void grow();

private:

    //ListItemType items[MAX_LIST];

    ListItemType *items;
    int size;
    int capacity;

    stack<ListItemType> related;


};

#endif // SORTEDMOVIELIST_H



/*
 *    ListItemType *items = new [Capacity];

    if(size == capacity)
    {
        Capacity *= 2;
        ListItemType *newItems = new [Capacity]
        for(int i=0; i<size;i++)
                newItems[i] = items[i];

        delete [] items;
        items = newItems;

    }
*/
