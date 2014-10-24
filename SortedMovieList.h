#ifndef SORTEDMOVIELIST_H
#define SORTEDMOVIELIST_H

#include "MovieType.h"
#include <stack>
//const int MAX_LIST = 20;
//typedef MovieType T;

using namespace std;


template<class T>
class SortedMovieList{
public:
    SortedMovieList();
    ~SortedMovieList();
    bool isEmpty() const;
    int getLength() const;

    bool insert(int index, T newItem);
    bool add(const T& newItem); //For adding from file AND user input
    int find(string name);                //Finds a movie in database, returns an index
    bool remove(int index);               //Deletes movie from database
    void retrieve(int index, T& item);         //Retrieves item at index, returns it by reference in return



    //Miscellaneous.
    bool findWithStar(int index, string& star);
    bool findRelated(string name);
    int binarySearch(string name);

    void grow();

private:

    //T items[MAX_LIST];

    T *items;
    int size;
    int capacity;

    stack<T> related;


};

#endif // SORTEDMOVIELIST_H



/*
 *    T *items = new [Capacity];

    if(size == capacity)
    {
        Capacity *= 2;
        T *newItems = new [Capacity]
        for(int i=0; i<size;i++)
                newItems[i] = items[i];

        delete [] items;
        items = newItems;

    }
*/
