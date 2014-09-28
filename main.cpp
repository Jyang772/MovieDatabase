#include <iostream>
#include <string>
#include "MovieType.h"
#include "SortedMovieList.h"
#include "algorithm"
#include "fstream"



using namespace std;



int main()
{
    ifstream file;
    file.open("data");

    SortedMovieList dataBank;
    MovieType Test;
    MovieType Test2,Test3,Test4;
    Test.ReadOneMovieFromFile(file);
    Test2.ReadOneMovieFromFile(file);
    file.close();


    Test.Display();
    cout << "\n";
    Test2.Display();

    Test3.m_title = "ABC";
    Test4.m_title = "abZebra";



    dataBank.insert(0,Test);
    dataBank.add(Test2);
    dataBank.add(Test3);
    dataBank.add(Test4);
    dataBank.display();

    dataBank.retrieve("ab");

}




