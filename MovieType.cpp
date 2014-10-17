
#include "MovieType.h"
#include <iomanip>

void MovieType::Initialize(string title, int year, int receipts, string studio, string stars){
    m_title = title;
    m_year = year;
    m_receipts = receipts;
    m_studio = studio;
    m_stars = stars;
}

int MovieType::compareKeys(const MovieType &p2){

    //return(m_title.compare(p2.m_title));

    //Doing it the "hard" way
   // m_title.

        int length = m_title.length() > p2.m_title.length() ? m_title.length() : p2.m_title.length();        //Compare each character. Z > A. If greater than and index of original title == 0. Done. Otherwise continue.
        //Iterate through each character. If a character is greater than the other, return -1,0,1.
        //If is first character, exit loop and return value. Otherwise if same characters, continue thru until diff. character
        //Use tolower because case must be same. Otherwise a > P ??? or A < a (a-P) == 17
            for(int i=0; i<length;i++)
            {
                 if(tolower(m_title[i]) > tolower(p2.m_title[i])){
                    return 1;
                }
                else if(tolower(m_title[i]) < tolower(p2.m_title[i])){
                    return -1;
                }
            }
            return 0;
}

int MovieType::compareKeys(string title){

    int length = m_title.length() > title.length() ? m_title.length() : title.length();        //Compare each character. Z > A. If greater than and index of original title == 0. Done. Otherwise continue.
    //Iterate through each character. If a character is greater than the other, return -1,0,1.
    //If is first character, exit loop and return value. Otherwise if same characters, continue thru until diff. character
    //Use tolower because case must be same. Otherwise a > P ??? or A < a (a-P) == 17
        for(int i=0; i<length;i++)
        {
             if(tolower(m_title[i]) > tolower(title[i])){
                return 1;
            }
            else if(tolower(m_title[i]) < tolower(title[i])){
                return -1;
            }
        }
        return 0;
}

void MovieType::Display(){
    cout << setw(20);
    cout << "Movie: " << m_title << endl;
    cout << setw(20);
    cout << "Year: " << m_year << endl;
    cout << setw(22);
    cout << "Receipt: $ " << m_receipts << endl;
    cout << setw(20);
    cout << "Studio: " << m_studio << endl;
    cout << setw(20);
    cout << "Stars: " << m_stars << endl;
}

bool MovieType::ReadOneMovieFromFile(ifstream& file){

    string sentinel = "***";
    getline(file,m_title);

    if(m_title == sentinel){
        return false;}

    file >> m_year;
    file >> m_receipts;
    file >> m_studio;
    getline(file,m_stars);

    if(m_stars != "")
        m_stars = m_stars.substr(m_stars.find(",")+2);


    return true;
}





bool MovieType::findRelated(string & name)
{
    int match = 0;

    for(unsigned int j=0; j<m_title.length();j++){
        if(tolower(m_title[j]) == tolower(name[match]))
            match++;
        else{
            if(tolower(m_title[j]) == tolower(name[0]))
                match = 1;
            else
                match = 0;
        }
        if(match == name.length()){
            return true;
        }
        else if(match == name.length()/2){
            return true;
        }
    }

    return false;
}
