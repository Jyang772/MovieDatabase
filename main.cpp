#include "Menu.h"
#include "MovieType.h"
#include "SortedMovieList.h"
#include "algorithm"
#include "fstream"
#include <iostream>
#include <string>


template <class ListItemType>
void ReadAllFromFile(ifstream& file, SortedMovieList<ListItemType>& dataBank){
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
    string fileName = "Movies1.txt";
    file.open(fileName.c_str());// open???

    if(!file.is_open())
        cout << "ERROR! " << fileName << " NOT FOUND!\n";

    SortedMovieList<MovieType> dataBank;
    Menu<MovieType> menu(&dataBank); //Initialize this menu with a dataBank.
    ReadAllFromFile(file, dataBank);

    bool quit = false;
    int choice;

    do{
        cout << "------------------------------" << endl;
        cout << "Movie Database" << endl;
        cout << "------------------------------" << endl;
        cout << "[1] View All" << endl;
        cout << "[2] Search" << endl;
        cout << "[3] Movies with Star" << endl;
        cout << "[4] Delete" << endl;
        cout << "[5] Add" << endl;
        cout << "[6] Count" << endl;
        cout << "[7] Quit" << endl;


        cin >> choice;
        if(!cin){
            cin.clear();
        }

        cin.ignore(50,'\n');

        switch(choice){
        //skips here.
        case 1:
        {
            menu.DisplayAllMovies();
            break;
        }
        case 2:
        {
            menu.SearchMovies();
            break;
        }
        case 3:
        {
            menu.MoviesWithStar();
            break;
        }
        case 4:
        {
            menu.DeleteMovie();
            break;
        }
        case 5:
        {
            menu.AddMovie();
            break;
        }
        case 6:
        {
            menu.CountMovies();
            break;
        }
        case 7:
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




