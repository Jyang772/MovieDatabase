#include "SortedMovieList.h"
#include "algorithm"

#ifndef max
#define max(x,y) ((x) > (y) ? (x) : (y))
#endif

//#define DEBUG

SortedMovieList::SortedMovieList() : size(0){}

bool SortedMovieList::isEmpty() const{
    return(size == 0 ? 1 : 0);
}

int SortedMovieList::getLength() const{
    return size;
}

bool SortedMovieList::remove(int index){

    for(int i=index; i<size;i++)
        items[i] = items[i+1];

    --size;
    return true;

}

bool SortedMovieList::insert(int index, ListItemType newItem){
    //Insert MovieType structure into list

    if(size+1 > MAX_LIST || index < 0)
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

    string newTitle = newItem.m_title;
    string strCmp; //For comparing titles;
    int index = 0;
    bool done = false;


    for(int i=0; i<size;i++){

//        if(items[i].compareKeys(newItem) > 0 && (i==0)){
//            index = 0;
//            cout << "newItem1: " << newItem.m_title << endl;
//        }
         if(items[i].compareKeys(newItem) > 0){
            index = i;
            break;
        }
        else if(items[i].compareKeys(newItem) < 0){
            index = i+1;
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

void SortedMovieList::display() const {

    for(int i=0; i<size;i++)
        cout << items[i].m_title << endl;
}

bool SortedMovieList::retrieve(int index, ListItemType &dataItem) const{

    if( index < 0 || index >= size )
        return false;  // bad index

    dataItem = items[index];

    return true;

}





void SortedMovieList::retrieve(string name) const{

    string compare;
    int match = 0;
    for(int i=0; i<size;i++)
    {
        compare.resize(items[i].m_title.length());
        transform(items[i].m_title.begin(),items[i].m_title.end(),compare.begin(),::tolower);
        cout << "compare: " << compare << endl;

        if(compare.compare(name) == 0){
            display(items[i]);
            return;
        }
    }

    cout << "\nMovie Not Found. Did you mean?\n" << endl;

    for(int i=0; i<size;i++){
        for(int j=0; j<items[i].m_title.length();j++){
            if(tolower(items[i].m_title[j]) == tolower(name[match]))
                match++;
            else{
                if(tolower(items[i].m_title[j]) == tolower(name[0]))
                    match = 1;
                else
                    match = 0;
            }
            if(match == name.length()){
                display(items[i]);
                break;}
        }
    }


    cout << "Movie Not Found" << endl;

}

void SortedMovieList::display(const ListItemType &dataItem) const{

    cout << "Movie: " << dataItem.m_title << endl;
    cout << "Year: " << dataItem.m_year << endl;
    cout << "Receipt: $ " << dataItem.m_receipts << endl;
    cout << "Studio: " << dataItem.m_studio << endl;
    cout << "Stars: " << dataItem.m_stars << endl;
}
