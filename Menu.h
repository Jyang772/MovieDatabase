#ifndef MENU_H
#define MENU_H

#include "SortedMovieList.h"

class Menu{
public:
    Menu(SortedMovieList*);
    void DisplayAllMovies();

    //void DisplayAllMovies();
    void SearchMovies();
    void DeleteMovie();
    void AddMovie();
    void CountMovies();

private:
    SortedMovieList* DataBank;
    MovieType temp;
    string prompt;
};

#endif // MENU_H
