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
    cout<<"1. Display Data" << endl;
    cout<<"2. Load Data" << endl;
    cout<<"3. Add Data" << endl;
    cout<<"4. Search Date"<< endl;
    cout<<"5. Modify Data" << endl;
    cout<<"6. Exit" << endl;

    cin >> selection;
    cin.ignore();

    if (selection == 1)
    {
        DisplayData();
    }
    if(selection == 6)
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