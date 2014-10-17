#include "SortedMovieList.h"
#include <algorithm>
#include <iomanip>

#ifndef max
#define max(x,y) ((x) > (y) ? (x) : (y))
#endif

//#define DEBUG

SortedMovieList::SortedMovieList() : size(0){}


bool SortedMovieList::isEmpty() const{
    // Determines whether a list is empty.
    // Precondition: None.
    // Postcondition: Returns true if the list is empty;
    // otherwise returns false.

    return(size == 0 ? 1 : 0);
}

int SortedMovieList::getLength() const{

    // Determines the length of a list.
    // Precondition: None.
    // Postcondition: Returns the number of items
    // that are currently in the list.
    return size;
}

bool SortedMovieList::insert(int index, ListItemType newItem){
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

    if(size == MAX_LIST || index < 0 || index > size )
        return false;


    for(int i=size; i>index;i--) //Move everything up by one
        items[i] = items[i-1];

    items[index] = newItem;
    ++size; //Increment size

    return true;  //Operation was a success.
}

bool SortedMovieList::add(const ListItemType &newItem){
    //Insert MovieType structure last

    if(size == MAX_LIST)
        return false;

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
    cout << "-----" << endl;
#endif
}



int SortedMovieList::find(string name) {

    //transform(name.begin(),name.end(),name.begin(),::tolower);

    cout << "name: " << name << endl;
    for(int i=0; i<size;i++)
    {

        if(items[i].compareKeys(name) == 0)
            return i;
    }

    return -1;

}

bool SortedMovieList::remove(int index){
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



//Displaying Movies operations

void SortedMovieList::retrieve(int index, ListItemType& item){
    // Retrieves a list item by position.
    // Precondition: index is the number of the item to
    // be retrieved.
    // Postcondition:
    // dataItem is the value of the desired item

    item = items[index];

}


bool SortedMovieList::findRelated(string name){

    int matches = 0;

    for(int i=0; i<size;i++){

        if(items[i].findRelated(name)){
            ++matches;
            items[i].Display();
        }
    }

    if(matches == 0)
        return false;

    return true;
}


//EXTRA PARTS


//template class SortedMovieList<MovieType>;






//        /*****/
//        /*Binary Search*/

//        cout << "size: " << size << endl;
//        int mid = size/2;
//        int first = 0, last = size;
//        string compare;

//        while(true){

//            compare.resize(items[mid].m_title.length());
//            transform(items[mid].m_title.begin(),items[mid].m_title.end(),compare.begin(),::tolower);

//            if(compare.compare(name) == 0){
//                display(items[mid]);
//                remove(mid);
//                return;
//            }
//            else if(name.compare(compare) < 0)
//                last = mid - 1;
//            else
//                first = mid + 1;

//            if(first > last)
//                break;

//            mid = (first + last)/2;
//        }
//        /****/


//    /*****/
//    /*Binary Search*/

//    cout << "size: " << size << endl;
//    int mid = size/2;
//    int first = 0, last = size;

//    while(true){

//        compare.resize(items[mid].m_title.length());
//        transform(items[mid].m_title.begin(),items[mid].m_title.end(),compare.begin(),::tolower);

//        if(compare.compare(name) == 0){
//            display(items[mid]);
//            return;
//        }
//        else if(name.compare(compare) < 0)
//            last = mid - 1;
//        else
//            first = mid + 1;

//        if(first > last)
//            break;

//        mid = (first + last)/2;
//    }
//    /****/
