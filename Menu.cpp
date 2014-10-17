#include "Menu.h"


Menu::Menu(SortedMovieList* DataBank) : DataBank(DataBank){
    //DataBank = DataBank;
    prompt = "Press [ENTER] to continue...\n";
}

void Menu::DisplayAllMovies(/*SortedMovieList& DataBank*/){


    cout << "Displaying all Movies: \n";
    for(int i=0; i<DataBank->getLength();i++){

        DataBank->retrieve(i,temp);
        temp.Display();
        cout << "\n";

        if((i+1) % 3 == 0)
            cin.get();
    }

    cout << prompt;
    cin.get();
}

void Menu::SearchMovies(){

    int index = -1;
    string input;
    cout << "Enter movie title: ";
    getline(cin,input);

    index = DataBank->find(input);

    if(index != -1){
        DataBank->retrieve(index,temp);
        temp.Display();
        cin.get();
        return;
    }

        cout << "\nMovie Not Found.\n\n";
        cout << "Displaying similar results: " << endl;

        if(!DataBank->findRelated(input))
            cout << "0 similar movies found.\n";

        cout << prompt;
        cin.get();
        return;
}

void Menu::DeleteMovie(){

    int index = -1;
    string input;
    cout << "Enter movie title: ";
    getline(cin,input);


    index = DataBank->find(input);

    if(DataBank->remove(index))
        cout << input << " has been removed.\n";
    else
        cout << "Movie Not Found!\n";

    cout << prompt;
    cin.get();
}

void Menu::AddMovie(){

    cout << "\nAdd movie to database:\n";

    string title,studio,stars;
    int year,receipt;
    cout << "Movie title: ";
    getline(cin,title);
    cout << "Studio: ";
    getline(cin,studio);
    cout << "Year: ";
    cin >> year;
    cout << "Gross receipts: ";
    cin >> receipt;
    cin.ignore(50,'\n');
    cout << "Stars: ";
    getline(cin,stars);

    temp.Initialize(title,year,receipt,studio,stars);

    if(DataBank->add(temp))
        cout << "Movie added successfully.\n";
    else
        cout << "Error! Database full.\n";
    cout << prompt;
    cin.get();
}

void Menu::CountMovies(){
    cout << "Number of movies: " << DataBank->getLength() << "\n";
    cout << prompt;
    cin.get();
}
