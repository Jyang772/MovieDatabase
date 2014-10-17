#ifndef MENU_H
#define MENU_H

#include "SortedMovieList.h"

class Menu{
public:
    Menu(SortedMovieList*);
    void DisplayAllMovies();
    void SearchMovies();
    void DeleteMovie();
    void AddMovie();
    void CountMovies();



    //Miscellaneous:
    void MoviesWithStar();



private:
    SortedMovieList* DataBank;
    MovieType temp;
    string prompt;
};

#endif // MENU_H
