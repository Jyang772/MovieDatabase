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
    file.open("Movies1.txt");

    bool quit = false;
    int choice;

    SortedMovieList<MovieType> dataBank;
    MovieType Test;
    MovieType Test2,Test3,Test4;

    Test3.m_title = "ABC";
    Test4.m_title = "abZebra";

    dataBank.add(Test3);
    dataBank.add(Test4);


    int max = 20;
    MovieType temp;
    MovieType a[max];
    int i=0;
    while((i<max) && a[i].ReadOneMovieFromFile(file)){
        dataBank.add(a[i]);
        i++;

    }

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
    cin.ignore(50,'\n');

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
        getline(cin,input);
       // cin >> input;
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




