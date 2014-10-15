#include "SortedMovieList.h"
#include "algorithm"

#ifndef max
#define max(x,y) ((x) > (y) ? (x) : (y))
#endif

//#define DEBUG

template<class ListItemType>
SortedMovieList<ListItemType>::SortedMovieList() : size(0){}

template<class ListItemType>
bool SortedMovieList<ListItemType>::isEmpty() const{
    // Determines whether a list is empty.
    // Precondition: None.
    // Postcondition: Returns true if the list is empty;
    // otherwise returns false.

    return(size == 0 ? 1 : 0);
}

template<class ListItemType>
int SortedMovieList<ListItemType>::getLength() const{

    // Determines the length of a list.
    // Precondition: None.
    // Postcondition: Returns the number of items
    // that are currently in the list.
    return size;
}

template<class ListItemType>
bool SortedMovieList<ListItemType>::remove(int index){

    for(int i=index; i<size;i++)
        items[i] = items[i+1];

    --size;
    return true;

}
template<class ListItemType>
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

    if(size == MAX_LIST || index < 0 || index > size )
        return false;


    for(int i=size; i>index;i--) //Move everything up by one
        items[i] = items[i-1];

    items[index] = newItem;
    ++size; //Increment size

    return true;  //Operation was a success.
}

template<class ListItemType>
bool SortedMovieList<ListItemType>::add(const ListItemType &newItem){
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

template<class ListItemType>
void SortedMovieList<ListItemType>::display() const {

    for(int i=0; i<size;i++)
    {
        cout << "Movie: " << items[i].m_title << "\n";
        cout << "Year: " << items[i].m_year << "\n";
        cout << "Receipt: $ " << items[i].m_receipts << "\n";
        cout << "Studio: " << items[i].m_studio << "\n";
        cout << "Stars: " << items[i].m_stars << "\n";
        cout << endl;

    }
}

template<class ListItemType>
bool SortedMovieList<ListItemType>::retrieve(int index, ListItemType &dataItem) const{

    if( index < 0 || index >= size )
        return false;  // bad index

    dataItem = items[index];

    return true;

}


//Overloaded functions

template<class ListItemType>
void SortedMovieList<ListItemType>::add(){

    ListItemType temp;

    cout << "Movie Title: ";
    getline(cin,temp.m_title);
    cout << "Studio: ";
    getline(cin,temp.m_studio);
    cout << "Year: ";
    getline(cin,temp.m_year);
    cout << "Gross receipt: ";
    getline(cin,temp.m_receipts);
    cout << "Stars: ";
    getline(cin,temp.m_stars);


    add(temp);
}

template<class ListItemType>
void SortedMovieList<ListItemType>::remove(string name){

    for(int i=0; i<size;i++){
        string compare;
        compare.resize(items[i].m_title.length());
        transform(items[i].m_title.begin(),items[i].m_title.end(),compare.begin(),::tolower);
        transform(name.begin(),name.end(),name.begin(),::tolower);

        if(compare.compare(name) == 0)
        {
            remove(i);
            return;
        }
    }
}

template<class ListItemType>
void SortedMovieList<ListItemType>::retrieve(string name) const{
    // Retrieves a list item by position.
    // Precondition: index is the number of the item to
    // be retrieved.
    // Postcondition: If 0 <= index < getLength(),
    // dataItem is the value of the desired item and
    // true is returned; otherwise false is returned.


    string compare;
    unsigned int match = 0;
    int matches = 0;

    transform(name.begin(),name.end(),name.begin(),::tolower);

    for(int i=0; i<size;i++)
    {
        compare.resize(items[i].m_title.length());
        transform(items[i].m_title.begin(),items[i].m_title.end(),compare.begin(),::tolower);

        if(compare.compare(name) == 0){
            display(items[i]);
            return;
        }
    }

    cout << "\nMovie Not Found. Displaying similar results:\n" << endl;

    for(int i=0; i<size;i++){
        for(unsigned int j=0; j<items[i].m_title.length();j++){
            if(tolower(items[i].m_title[j]) == tolower(name[match]))
                match++;
            else{
                if(tolower(items[i].m_title[j]) == tolower(name[0]))
                    match = 1;
                else
                    match = 0;
            }
            if(match == name.length()){
                ++matches;
                display(items[i]);
                break;}
            else if(match == name.length()/2){
                ++matches;
                display(items[i]);
                break;}
        }
    }

    if(matches == 0)
        cout << "0 similar movies found.\n\n";

}


template<class ListItemType>
void SortedMovieList<ListItemType>::display(const ListItemType &dataItem) const{

    /*Precondition: None.
     * Postcondition: Displays all info about a movie.
     *
    */

    cout << "Movie: " << dataItem.m_title << endl;
    cout << "Year: " << dataItem.m_year << endl;
    cout << "Receipt: $ " << dataItem.m_receipts << endl;
    cout << "Studio: " << dataItem.m_studio << endl;
    cout << "Stars: " << dataItem.m_stars << endl;
}


template class SortedMovieList<MovieType>;





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
