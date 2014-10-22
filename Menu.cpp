#include "Menu.h"


Menu::Menu(SortedMovieList* DataBank) : DataBank(DataBank){
    //DataBank = DataBank;
    prompt = "Press [ENTER] to continue...\n";
}

void Menu::DisplayAllMovies(/*SortedMovieList& DataBank*/){
    //Precondition: None.
    //Postcondition: Output all movies in database.
    //Iterates through DataBank items and calls their Display() function.


    cout << "Displaying all Movies: \n";

    MovieType temp;

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
    //Precondition: None.
    //Postcondition: Matched and Related movies are displayed.
    //Gets user input, attempts to find movie in database. If not found, show related movies.

    MovieType temp;
    int index = -1;
    string input;
    cout << "Enter movie title: ";
    getline(cin,input);

    index = DataBank->find(input);

    if(index != -1)
    {
        DataBank->retrieve(index,temp);
        temp.Display();
        cin.get();
        return;
    }

    cout << "\nMovie Not Found.\n\n";
//    cout << "Displaying similar results: " << endl;



//    //Miscellaneous
//    if(!DataBank->findRelated(input))
//        cout << "0 similar movies found.\n";

    cout << prompt;
    cin.get();
    return;
}

void Menu::DeleteMovie(){
    //Precondition: None.
    //Postcondition: Movie is deleted if found.
    //Gets user input. If movie exists it is deleted. Otherwise show error message.

    int index = -1;
    string input;
    cout << "Enter movie title: ";
    getline(cin,input);


    index = DataBank->find(input);

    if(index != -1){
        if(DataBank->remove(index) != -1)
        cout << input << " has been removed.\n";
    }
    else
        cout << "Movie Not Found!\n";

    cout << prompt;
    cin.get();
}

void Menu::AddMovie(){
    //Precondition: None.
    //Postcondition: New movie is added to database.
    //Get user input. Use temporary MovieType object to add to DataBase.
    //If successful, return message. If not, return error message.

    cout << "\nAdd movie to database:\n";

    MovieType temp;
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
    //Precondition: None.
    //Postcondition: Display total movies in database.
    //Call DataBank getLength() method.

    cout << "Number of movies: " << DataBank->getLength() << "\n";
    cout << prompt;
    cin.get();
}






//Miscellaneous:

void Menu::MoviesWithStar()
{
    //Precondition: None.
    //Postcondition: Display movies with star.
    //Searches DataBank items calling findWithStar() method.


    string star;
    cout << "Enter Star's Name: ";
    getline(cin,star);


    MovieType temp;
    int size = DataBank->getLength();

    for(int i=0; i < size; i++)
    {
        if(DataBank->findWithStar(i,star))
        {
            DataBank->retrieve(i,temp);
            temp.Display();
            cout << "\n";
        }
    }

    cout << prompt << endl;
    cin.get();

}
