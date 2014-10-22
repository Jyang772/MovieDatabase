#include "SortedMovieList.h"
#include <algorithm>
#include <iomanip>

#ifndef max
#define max(x,y) ((x) > (y) ? (x) : (y))
#endif

//#define DEBUG

template <class ListItemType>
SortedMovieList<ListItemType>::SortedMovieList() : size(0){

    capacity = 10;
    items = new ListItemType[capacity];
}

template <class ListItemType>
SortedMovieList<ListItemType>::~SortedMovieList(){
    delete [] items;
}

template <class ListItemType>
bool SortedMovieList<ListItemType>::isEmpty() const{
    // Determines whether a list is empty.
    // Precondition: None.
    // Postcondition: Returns true if the list is empty;
    // otherwise returns false.

    return(size == 0 ? 1 : 0);
}

template <class ListItemType>
int SortedMovieList<ListItemType>::getLength() const{

    // Determines the length of a list.
    // Precondition: None.
    // Postcondition: Returns the number of items
    // that are currently in the list.
    return size;
}

template <class ListItemType>
bool SortedMovieList<ListItemType>::insert(int index, ListItemType newItem){
    // Inserts an item into the list at position index.
    // Precondition: index indicates the position at which
    // the item should be inserted in the list.
    // Postcondition: If insertion is successful, newItem is
    // at position index in the list, and other items are
    // renumbered accordingly, and true is returned;
    // otherwise false is returned.
    // Note: Insertion will not be successful if
    // index < 0 or index > getLength().


    //Insert MovieType structure into list

    if(index < 0 || index > size )
        return false;


    for(int i=size; i>index;i--) //Move everything up by one
        items[i] = items[i-1];

    items[index] = newItem;
    ++size; //Increment size

    return true;  //Operation was a success.
}

template <class ListItemType>
bool SortedMovieList<ListItemType>::add(const ListItemType &newItem){
    //Insert MovieType structure last

//    if(size == MAX_LIST)
//        return false;

    if(size == capacity)
        grow();


    int index = size; //Set to last if item is bigger than rest

    for(int i=0; i<size;i++)
    {
        if(items[i].compareKeys(newItem) > 0)
        {
            index = i;
            break;
        }
    }

    insert(index,newItem);


#ifdef DEBUG
    cout << "index: " << index << endl;
    cout << "size: " << size << endl;
    cout << "getLength-----" << endl;
#endif
    return true;
}

template <class ListItemType>
void SortedMovieList<ListItemType>::grow(){

    capacity *= 2;

    ListItemType *newItems = new ListItemType[capacity];

    for(int i=0; i<size; i++)
        newItems[i] = items[i];

    delete [] items;

    items = newItems;

}

template <class ListItemType>
int SortedMovieList<ListItemType>::find(string name) {
    //Precondition: string is valid.
    //Postcondition: returns index of movie with same title.
    //Iterates through list finding movie with same title. Return index if found,
    //else return -1.


    for(int i=0; i<size;i++)
    {

        if(items[i].compareKeys(name) == 0)
            return i;
    }

    return -1;

}

template <class ListItemType>
bool SortedMovieList<ListItemType>::remove(int index){
    /*Precondition: Takes movie index
     * Postcondition: Removes movie at index
     * Returns true if removed. Otherwise return false if index == -1
     * */


    if(index != -1)
    {
        for(int i=index; i<size;i++)
            items[i] = items[i+1];
        --size;
        return true;
    }

    return false;


}

template <class ListItemType>
void SortedMovieList<ListItemType>::retrieve(int index, ListItemType& item){
    // Retrieves a list item by position.
    // Precondition: index is the number of the item to
    // be retrieved.
    // Postcondition:
    // dataItem is the value of the desired item

    item = items[index];

}



//EXTRA PARTS

template <class ListItemType>
bool SortedMovieList<ListItemType>::findRelated(string name){

    int matches = 0;

    for(int i=0; i<size;i++){

        if(items[i].findRelated(name)){
            ++matches;
            //items[i].Display();
            //cout << "\n";
            related.push(items[i]);
        }
    }


    for(int i=0, size = related.size(); i<size; i++){
        related.top().Display();
        related.pop();
        cout << "\n";
    }

    if(matches == 0)
        return false;

    return true;
}

template <class ListItemType>
int SortedMovieList<ListItemType>::binarySearch(string name){

            /*****/
            /*Binary Search*/

            cout << "size: " << size << endl;
            int mid = size/2;
            int first = 0, last = size;

            while(true){

                if(items[mid].compareKeys(name) == 0){
                    return mid;
                }
                else if(items[mid].compareKeys(name) > 0)   //If item name is greater than name at [mid]. Name must be before [mid]. Set last to [mid] - 1
                    last = mid - 1;
                else
                    first = mid + 1;

                if(first > last){
                    break;
                }

                mid = (first + last)/2;
            }

           return -1;


}

template <class ListItemType>
bool SortedMovieList<ListItemType>::findWithStar(int index, string& star){

    if(items[index].HasStar(star))
        return true;

    return false;
}



template class SortedMovieList<MovieType>; //Explicitly instantiate template class for MovieType


