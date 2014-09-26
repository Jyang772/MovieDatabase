#include <iostream>
#include <string>
#include "MovieType.h"
#include "SortedMovieList.h"

using namespace std;



int main()
{
    SortedMovieList dataBank;
    MovieType Test;
    MovieType Test2,Test3,Test4;
    Test.ReadOneMovieFromFile();
    //Test.Display();


    Test2.m_title = "Z1";
    Test3.m_title = "Z";
    Test4.m_title = "Z8";


    dataBank.insert(0,Test);
    dataBank.add(Test2);
    dataBank.add(Test3);
    dataBank.add(Test4);
    dataBank.display();



}

