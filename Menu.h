#ifndef MENU_H
#define MENU_H

#include "SortedMovieList.h"

template <class ListItemType>
class Menu{
public:
    Menu(SortedMovieList<ListItemType>*);
    void DisplayAllMovies();
    void SearchMovies();
    void DeleteMovie();
    void AddMovie();
    void CountMovies();



    //Miscellaneous:
    void MoviesWithStar();


private:
    SortedMovieList<ListItemType>* DataBank;
    //MovieType temp;//local var?
    string prompt;
};


#endif // MENU_H
