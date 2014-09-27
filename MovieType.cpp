
#include "MovieType.h"

void MovieType::Initialize(string title, string year, string receipts, string studio, string stars){
    m_title = title;
    m_year = year;
    m_receipts = receipts;
    m_studio = studio;
    m_stars = stars;
}

int MovieType::compareKeys(const MovieType &p2){
    //return m_title == p2.m_title;

    //return(m_title.compare(p2.m_title));



        int length = m_title.length() > p2.m_title.length() ? m_title.length() : p2.m_title.length();        //Compare each character. Z > A. If greater than and index of original title == 0. Done. Otherwise continue.


            for(int i=0; i<length;i++)
            {
                if(tolower(m_title[i]) > tolower(p2.m_title[i]) && i == 0){
                    return 1;
                }
                else if(tolower(m_title[i]) > tolower(p2.m_title[i])){
                    return 1;
                }
                else if(tolower(m_title[i]) < tolower(p2.m_title[i])){
                    return -1;
                }
            }
            return 0;
}

void MovieType::Display(){
    cout << "Movie: " << m_title << endl;
    cout << "Year: " << m_year << endl;
    cout << "Receipts: $ " << m_receipts << endl;
    cout << "Studios: " << m_studio << endl;
    cout << "Stars: " << m_stars << endl;
}

bool MovieType::ReadOneMovieFromFile(ifstream& file){

    string line, lastLine;

    getline(file,m_title);
    if(m_title == "***")
        return false;
    file >> m_year;
    file >> m_receipts;
    file >> m_studio;
    getline(file,m_stars);

    m_stars = m_stars.substr(m_stars.find(",")+2,m_stars.length());

    return true;
}

