
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
    //Precondition: Valid MovieType.
    //Postcondition: Returns -1, 1, 0 based on character comparison.
    //Compare each character of title. First character with difference determines result.

    //return(m_title.compare(p2.m_title));  //Easier method ; does not account for case difference.

    //Doing it the "hard" way

    int length = m_title.length() > p2.m_title.length() ? p2.m_title.length() : m_title.length();


    //Compare each character. Z > A. If greater than and index of original title == 0. Done. Otherwise continue.
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
    //Precondition: Valid string.
    //Postcondition: Returns -1, 1, 0 based on character comparison.
    //Compare each character of title. First character with difference determines result.

    int length = m_title.length() > title.length() ? title.length() : m_title.length();


        if(m_title.length() != title.length())
            return -1;

    //Compare each character. Z > A. If greater than and index of original title == 0. Done. Otherwise continue.
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
    //Precondition: None.
    //Postcondition: Displays Movie info.

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

    //Precondition: File exists and can be opened.
    //Postcondition: File data is read in and stored in DataBank.


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



//Miscellaneous:

bool MovieType::findRelated(string & name){

    //Precondition: valid name.
    //Postcondition: Display related movies.
    //Character comparison. Any substring that is matched will have the whole title displayed. Returns true;

    unsigned int match = 0;

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

bool MovieType::HasStar(string& star){

    //Precondition: string is valid.
    //Postcondition: Returns true if movie contains star, else return false.


    unsigned int match = 0;

    for(unsigned int j=0; j<m_stars.length();j++){
        if(tolower(m_stars[j]) == tolower(star[match]))
            match++;
        else{
            if(tolower(m_stars[j]) == tolower(star[0]))
                match = 1;
            else
                match = 0;
        }
        if(match == star.length()){
            return true;
        }
        else if(match == star.length()/2){
            return true;
        }
    }


    return false;
}
