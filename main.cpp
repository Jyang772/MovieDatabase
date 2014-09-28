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

    bool quit = false;
    int choice;

    SortedMovieList dataBank;
    MovieType Test;
    MovieType Test2,Test3,Test4;
    Test.ReadOneMovieFromFile(file);
    Test2.ReadOneMovieFromFile(file);

    file.close();

    MovieType *lawl = new MovieType[2];
    MovieType *lol;


    for(int i=0; i<2;i++){
        lol = new MovieType;
        lol->m_title = i+1;
        lawl[i] = *lol;
        delete lol;
    }

    cout << &lawl[0] << endl;
    cout << &lawl[1] << endl;

    delete [] lawl;


//    MovieType *lawl[2];
//    for(int i=0; i<2; i++){
//        lawl[2] = new MovieType;
//    }


    Test.Display();
    cout << "\n";
    Test2.Display();

    Test3.m_title = "ABC";
    Test4.m_title = "abZebra";



    dataBank.insert(0,Test);
    dataBank.add(Test2);
    dataBank.add(Test3);
    dataBank.add(Test4);
    //dataBank.display();


    do{
    cout << "------------------------------" << endl;
    cout << "Movie Database" << endl;
    cout << "------------------------------" << endl;
    cout << "[1] View" << endl;
    cout << "[2] Search" << endl;
    cout << "[3] Delete" << endl;
    cout << "[4] Add" << endl;
    cout << "[5] Count" << endl;
    cout << "[6] Quit" << endl;
    cin >> choice;

    switch(choice){
    //skips here. No declare variable lawuawlawl
    case 1:
    {
            dataBank.display();
            break;
    }
    case 2:
    {
        string input;
        cout << "Enter movie title: ";
        cin >> input;
        dataBank.retrieve(input);
        break;
    }
    case 3:
    {
        string input;
        cout << "Enter movie title: ";
        cin >> input;
        dataBank.remove(input);
        cout << input << " has been removed." << endl;
        break;
    }
    case 6:
        quit = true;


        }

    //cin.ignore();
    //cin.get();
    }while(!quit);

}




