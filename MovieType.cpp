
#include "MovieType.h"

#include "fstream"

void MovieType::Initialize(string title, string year, string receipts, string studio, string stars){
    m_title = title;
    m_year = year;
    m_receipts = receipts;
    m_studio = studio;
    m_stars = stars;
}

int MovieType::compareKeys(const MovieType &p2){
    return m_title == p2.m_title;
}

void MovieType::Display(){
    cout << "Movie: " << m_title << endl;
    cout << "Year: " << m_year << endl;
    cout << "Receipts: $ " << m_receipts << endl;
    cout << "Studios: " << m_studio << endl;
    cout << "Stars: " << m_stars << endl;
}

void MovieType::ReadOneMovieFromFile(){

    ifstream file;
    file.open("data");
    string line;

    getline(file,line); // First line (title)
    m_title = line;

    getline(file,line); // Second line(year, receipt)


    int space = line.find(" ");
    m_year.resize(space);       //Resize string length

    for(int i = 0; i < space; i++){
        m_year[i] = line[i];
        //cout << m_year[i] << endl;
    }

    m_receipts.resize(line.length()-space);
    for(int i = 0; i < line.length()-space-1; i++){
        m_receipts[i] = line[(space+1)+i];
    }
    cout << m_receipts << endl << endl;

    getline(file,line);
    space = line.find(",");
    m_studio.resize(space);

    for(int i=0; i<space;i++)
        m_studio[i] = line[i];


    m_stars.resize(line.length()-space);
    for(int i=0;i<line.length()-space;i++)
        m_stars[i] = line[(space+2)+i];     //+2 for ", "


   // m_receipts = line.substr(space+1,line.length());

    file.close();
}
