#ifndef MOVIETYPE_H
#define MOVIETYPE_H

#include <string>
#include <iostream>
using namespace std;


class MovieType{
public:
    void Initialize(string, string, string, string, string);
    int compareKeys(const MovieType& p2);
    void ReadOneMovieFromFile();
    void Display();


//private:
    string m_title; //key
    string m_year;
    string m_receipts;
    string m_studio;
    string m_stars;

};


#endif // MOVIETYPE_H