#include "SortedMovieList.h"

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

        if(items[i].compareKeys(newItem) < 0 && (i==0)){
            index = 0;
            cout << "newItem1: " << newItem.m_title << endl;
            break;
        }
        else if(items[i].compareKeys(newItem) < 0){
            cout << "newItem2: " << newItem.m_title << endl;

            index = i;
        }
        else if(items[i].compareKeys(newItem) > 0){
            cout << "newItem3: " << newItem.m_title << endl;

            index = i+1;
        }

    }

    insert(index,newItem);
cout << "------" << endl;


//    for(int i=0; i<size;i++)
//    {
//        strCmp = items[i].m_title;
//        int current = i;
//#ifdef DEBUG
//        cout << "items[i].title: " << strCmp << endl;
//        cout << "newTitle: " << newTitle << endl;
//#endif

////        cout << strCmp.compare(newTitle) << endl;
////        if((strCmp.compare(newTitle) > 0) && (i == 0)){ //If less than and index == 0
////            index = 0;
////            break;
////        }
////        else if(strCmp.compare(newTitle) > 0){      //If less than
////            index = i;
////            //break;
////        }
////        else if(strCmp.compare(newTitle) < 0){
////            index = i+1;
////            //break;
////        }


//    int length = max(strCmp.length(),newTitle.length());       //Compare each character. Z > A. If greater than and index of original title == 0. Done. Otherwise continue.

//        //int length = strCmp.length() > newTitle.length() ? strCmp.length() : newTitle.length();
//        //int length = strCmp.length();
//        // cout << "LENGTH: " << length << endl;

//        for(int i=0; i<length;i++)
//        {
//            if(strCmp[i] > newTitle[i] && current == 0){
//                index = 0;
//                done = true;
//                break;
//            }
//            else if(strCmp[i] > newTitle[i]){
//                index = current;
//                break;
//            }
//            else if(strCmp[i] < newTitle[i]){
//                index = current+1;
//                break;
//            }

//        }
//        if(done)
//            break;


//    }

#ifdef DEBUG
    cout << "index: " << index << endl;
    cout << "size: " << size << endl;
    cout << "-----" << endl;
#endif

    return true;
}

bool SortedMovieList::retrieve(int index, ListItemType &dataItem) const{

    if( index < 0 || index >= size )
        return false;  // bad index


    dataItem = items[index];

    return true;

}
void SortedMovieList::display() const {

    for(int i=0; i<size;i++)
        cout << items[i].m_title << endl;
}
