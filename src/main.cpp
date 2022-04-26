#include <iostream>
#include <sstream>
#include "Utility.h" //Header file
using namespace std;

//A vector to hold the data that will be stored at runtime
static vector<DailyData> dataList;
//A temporary vector to hold data (from things like searches)
//static vector<DailyData> temp;

void Menu()
{
    //Clears the console
    system("CLS");
    // a string to store the selection from the menu
    string selection = "";

    //Display the menu options
     cout<< "--------------------------------" << endl;
    cout<< "Welcome To The Weather App!" << endl;
    cout<< "--------------------------------\n" << endl;
    cout<<"1. Display All Data" << endl;
    cout<<"2. Display Data From File" << endl;
    cout<<"3. Load Data" << endl;
    cout<<"4. Search Data" << endl;
    cout<<"5. Clear Loaded Data"<< endl;
    cout<<"6. Sort Data"<<endl;
    cout<<"7. Exit\n" << endl;
    cout<< "--------------------------------\n" << endl;

    cout<< "Please select an option from the menu : ";


    //Ask for input and store it in the selection string
    getline(cin, selection);

    //checks for the matching option and calls that function (functions implemented in Utility.h)
    if (selection == "1")
    {
        //Clears the console
        system("CLS");
        DisplayAllData(dataList);
    }
    else if (selection == "2")
    {
        //Clears the console
        system("CLS");
        DisplayDataFromFile();
    }
    else if (selection == "3")
    {
        //Clears the console
        system("CLS");
        LoadData(dataList);
    }
    else if (selection == "4")
    {
        //Clears the console
        system("CLS");
        SearchData(dataList);
    }
    else if (selection == "5")
    {
        //Clears the console
        system("CLS");
        ClearData(dataList);
    }
    else if(selection == "6")
    {
        system("CLS");
        SortData(dataList);
    }
    else if(selection == "7")
    {
        return;
    }
    else
    {
        cout << "\nInvalid Selection" <<endl;        system("pause");
    }

    cout << "\nSelect from menu again" <<endl;
    system("pause");

    //Calls the menu again so that after any action has been done, it comes back to the menu
    Menu();
}

int main()
{

    Menu();

    //pauses the screen so that it does not exit immediately
    system("Pause");
    return 0;
}
