#ifndef MOVIETYPE_H
#define MOVIETYPE_H

#include <string>
#include <iostream>
#include "fstream"

using namespace std;

class MovieType{
public:
    void Initialize(string, int, int, string, string);
    int compareKeys(const MovieType& p2);
    int compareKeys(string);
    bool ReadOneMovieFromFile(ifstream&);
    void Display();
    bool findRelated(string&);

    //Miscellaneous
    bool HasStar(string&);

    bool operator>(const MovieType&);
    bool operator<(const MovieType&);
    bool operator>=(const MovieType&);
    bool operator<=(const MovieType&);
    bool operator==(const MovieType&);
    bool operator!=(const MovieType&);


private:
    int m_year;
    int m_receipts;
    string m_title; //key
    string m_studio;
    string m_stars;

};


#endif // MOVIETYPE_H
