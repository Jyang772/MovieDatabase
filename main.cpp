#include <iostream>
#include <string>
#include "MovieType.h"
#include "SortedMovieList.h"
#include "algorithm"
#include "fstream"


int main()
{
    ifstream file;
    file.open("Movies1.txt");

    bool quit = false;
    int choice;



    SortedMovieList dataBank;

    int max = 20;
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
        cout << "[1] View All" << endl;
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
            cin.get();
            break;
        }
        case 2:
        {
            string input;
            cout << "Enter movie title: ";
            getline(cin,input);
            dataBank.retrieve(input);
            break;
        }
        case 3:
        {
            string input;
            cout << "Enter movie title: ";
            getline(cin,input);
            if(dataBank.remove(input))
                cout << input << " has been removed.\n";
            cin.get();
            break;
        }
        case 4:
        {
            if(dataBank.add())
                cout << "Movie added successfully.\n";
            else
                cout << "Error! Database full.\n";
            break;
        }
        case 5:
        {
            cout << "Number of movies: " << dataBank.getLength();
            cin.get();
            break;
        }
        case 6:
            quit = true;
        }
    }while(!quit);

}




