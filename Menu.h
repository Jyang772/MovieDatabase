#ifndef MENU_H
#define MENU_H

#include "SortedMovieList.h"

template <class T>
class Menu{
public:
    Menu(SortedMovieList<T>*);
    void DisplayAllMovies();
    void SearchMovies();
    void DeleteMovie();
    void AddMovie();
    void CountMovies();



    //Miscellaneous:
    void MoviesWithStar();


private:
    SortedMovieList<T>* DataBank;
    //MovieType temp;//local var?
    string prompt;
};


#endif // MENU_H
