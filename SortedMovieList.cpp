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

int SortedMovieList::find(string name) {

    string compare;

    transform(name.begin(),name.end(),name.begin(),::tolower);

    for(int i=0; i<size;i++)
    {
        // compare.resize(items[i].m_title.length());
        //transform(items[i].m_title.begin(),items[i].m_title.end(),compare.begin(),::tolower);

        //        if(compare.compare(name) == 0){
        //            return i;
        //        }

        if(items[i].compareKeys(name) == 0)
          return i;
    }

    return 0;

}

bool SortedMovieList::remove(int index){

    for(int i=index; i<size;i++)
        items[i] = items[i+1];
    --size;

    return true;

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
    bool done = false;


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

    return true;
}


void SortedMovieList::display(){

    for(int i=0; i<size;i++)
    {
        display(items[i]);
        cout << endl;

    }
}


bool SortedMovieList::retrieve(int index, ListItemType &dataItem) {

    if( index < 0 || index >= size )
        return false;  // bad index

    dataItem = items[index];

    return true;

}


//Overloaded functions


void SortedMovieList::add(){

    string title,studio,stars;
    int year,receipt;
    cout << "Movie title: ";
    getline(cin,title);
    cout << "Studio: ";
    getline(cin,studio);
    cout << "Year: ";
    cin >> year;
    cout << "Gross receipts: ";
    cin >> receipt;
    cin.ignore(50,'\n');
    cout << "Stars: ";
    getline(cin,stars);

    ListItemType temp;
            temp.Initialize(title,year,receipt,studio,stars);

    add(temp);

}


bool SortedMovieList::remove(string name){

    int index = find(name);

    if(index)
    {
        remove(index);
        return true;
    }

    cout << "Movie not found.\n\n";
    return false;

}


void SortedMovieList::retrieve(string name){
    // Retrieves a list item by position.
    // Precondition: index is the number of the item to
    // be retrieved.
    // Postcondition: If 0 <= index < getLength(),
    // dataItem is the value of the desired item and
    // true is returned; otherwise false is returned.


    int index = -1, matches = 0;

    index = find(name);

    if(index){
        display(items[index]);
        return;
    }

    cout << "\nMovie Not Found.\n\n";

    cout << "Displaying similar results: " << endl;

        for(int i=0; i<size;i++){

            if(items[i].findRelated(name)){
                ++matches;
                display(items[i]);
            }
        }

            if(matches == 0)
                cout << "0 results found.\n\n";


}



void SortedMovieList::display(ListItemType &dataItem) {

    /*Precondition: None.
     * Postcondition: Displays all info about a movie.
     *
    */

    dataItem.Display();

}


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
