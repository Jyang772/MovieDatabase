#ifndef MENU_H
#define MENU_H

#include "SortedMovieList.h"

class Menu{
public:
    Menu(SortedMovieList*);
    void DisplayAllMovies(SortedMovieList&);
    void SearchMovies(SortedMovieList&);
    void DeleteMovie(SortedMovieList&);
    void AddMovie(SortedMovieList&);
    void CountMovies(SortedMovieList&);

private:
    //SortedMovieList* DataBank;
    MovieType temp;
    string prompt;
};

#endif // MENU_H
