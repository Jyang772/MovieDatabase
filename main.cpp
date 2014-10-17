#include "Menu.h"
#include "MovieType.h"
#include "SortedMovieList.h"
#include "algorithm"
#include "fstream"
#include <iostream>
#include <string>



void ReadAllFromFile(ifstream& file, SortedMovieList& dataBank){
    int max = 20;
    MovieType a[max];
    int i=0;
    while((i<max) && a[i].ReadOneMovieFromFile(file)){
        dataBank.add(a[i]);
        i++;
    }

}

int main()
{
    ifstream file;
    file.open("Movies1.txt");// open???

    bool quit = false;
    int choice;
    string prompt = "Press [ENTER] to continue...\n";


    SortedMovieList dataBank;
    Menu menu(&dataBank);
    ReadAllFromFile(file, dataBank);

    do{
        cout << "------------------------------" << endl;
        cout << "Movie Database" << endl;
        cout << "------------------------------" << endl;
        cout << "[1] View All" << endl;
        cout << "[2] Search" << endl;
        cout << "[3] Delete" << endl;
        cout << "[4] Add" << endl;
        cout << "[5] Count" << endl;
        cout << "[6] Quit" << endl;


        cin >> choice;
        cin.ignore(50,'\n');

        switch(choice){
        //skips here.
        case 1:
        {
            menu.DisplayAllMovies(dataBank);
            break;
        }
        case 2:
        {
            menu.SearchMovies(dataBank);
            break;
        }
        case 3:
        {
            menu.DeleteMovie(dataBank);
            break;
        }
        case 4:
        {
            menu.AddMovie(dataBank);
            break;
        }
        case 5:
        {
            menu.CountMovies(dataBank);
            break;
        }
        case 6:
        {
            quit = true;
            break;
        }
        default:
        {
            cout << "Please enter a valid selection.\n";
        }

        }
    }while(!quit);

}




