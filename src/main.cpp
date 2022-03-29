#include <iostream>
#include <stdlib.h>

using namespace std;

void DisplayData()
{
    cout << "Displaying Data..." << endl;
    system("pause");
}

void Menu()
{
    system("CLS");
    int selection = 0;

    cout << "Welcome To The Weather App!\n" << endl;
    cout<<"1. Insert weather data (txt file)" << endl;
    cout<<"2. Overall data statistics" << endl;
    cout<<"3. Add Data" << endl;
    cout<<"4. Search Date"<< endl;
    cout<<"5. Monthly statistics"<< endl
    cout<<"6. Total rainfall" << endl;
    cout<<"7. Exit" << endl;

    cin >> selection;
    cin.ignore();

    if (selection == 1)
    {
        DisplayData();
    }
    if(selection == 7)
    {
        return;
    }
    Menu();
}

int main()
{
    cout << "Welcome To The Weather App!" << endl;
    system("Pause");
    Menu();
    return 0;
}
