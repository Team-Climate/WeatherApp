//Header file
#pragma once
// Avoids libraries from being copied twice
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class DailyData
{
public:
//public variables to store the weather data per day
    int day;
    int year;
    int month;
    float maxTemp;
    float minTemp;
    float meltedRain;
    float snowPellets;
    float snowPelletsOnGround;

//An empty default constructor
    DailyData(){}

//A constructor that takes in a single line of data and stores it appropriately
    DailyData(string line)
    {
//The line of data has to be split into individual components
//This individual components are stored in temporary strings
       stringstream ss(line);
       string s_year, s_month, s_day, s_maxTemp, s_minTemp, s_meltedRain, s_snowPellets, s_snowPelletsOnGround;

//This stores data till it gets to a delimiter which is whitespace(' ') in this case
       getline(ss, s_year, ' ');
       getline(ss, s_month, ' ');
       getline(ss, s_day, ' ');
       getline(ss, s_maxTemp, ' ');
       getline(ss, s_minTemp, ' ');
       getline(ss, s_meltedRain, ' ');
       getline(ss, s_snowPellets, ' ');
       getline(ss, s_snowPelletsOnGround, ' ');

//The separated data is then moved from its temporary position to the variables in the class
//They are converted from strings to either integers(stoi()) or floats(stof())
       year = stoi(s_year);
       month = stoi(s_month);
       day = stoi(s_day);
       maxTemp = stof(s_maxTemp);
       minTemp = stof(s_minTemp);
       meltedRain = stof(s_meltedRain);
       snowPellets = stof(s_snowPellets);
       snowPelletsOnGround = stof(s_snowPelletsOnGround);
    }

//This method takes prints the summary using the data stored in the variables
    void Summary()
    {
      cout <<"\nWeather Summary for " <<month <<"/"<< day <<"/" << year <<endl
           <<"Max Temperature: "     << maxTemp <<endl
           <<"Min Temperature: "     << minTemp <<endl
           <<"Rain/Melted Snow(In): "<< meltedRain <<endl
           <<"Snow/Ice Pellets/Hail(In): " << snowPellets <<endl
           <<"Snow/Ice Pellets/Hail On Ground(In): " <<snowPelletsOnGround<<endl;
    }

//This method prints out a summary in an almost tabulated form
    void print()
    {
        cout << setw(11)  << to_string(month) + "/" + to_string(day) +"/" + to_string(year) << "  "
             << setw(3) << maxTemp << "  " << setw(3) << minTemp << "  "
             << setw(4) << meltedRain << "  " << setw(4) << snowPellets << "  "
             << setw(4) << snowPelletsOnGround << endl;

//The setw() functions here are for formatting the text with cout
    }

    float avgTemp()
    {
    	return (maxTemp + minTemp)/2;
    }
};

//A function to clear all data that was loaded during runtime
static void ClearData(vector<DailyData>& dataList)
{
    //it takes both vectors as parameters by reference and it clears them
    dataList.clear();
}

//This displays all the data that has been loaded during runtime
static void DisplayAllData(vector<DailyData>& dataList)
{
    if (dataList.size() == 0)
    {
        //Meaning that no data has been loaded yet
        cout << "Load Some Data First!!" << endl;
        return;
    }

    //Goes through the whole array and prints out the data
    for(int i = 0; i < dataList.size(); i++)
    {
        dataList[i].print();
    }
    cout << "\n Done" << endl;
    system("pause");
}


//This Function displays the content of any given file
static void DisplayDataFromFile()
{
    //Gets the path to the file
    string path;
    cout << "Enter the path to the file: ";
    getline(cin, path);

    //If no path was entered
    if(path == "")
    {
        cout << "No path entered!" << endl;
        return;
    }

    //Opens the file as specified by the path
    ifstream data;
    data.open(path.c_str(), ios::in);


    string currLine;
    cout << "Displaying Data from " << path <<endl;

    //Prints the file to the console line by line
    //Appends a line number as a prefix to each line
    int line = 0;
    while(getline(data, currLine))
    {
        cout << setw(3) << line <<": "<<currLine << endl;
        line++;
    }
}

//The function loads data from a file into the vector
//It takes the vector as a parameter by reference so it can change it
static void LoadData(vector<DailyData>& dataList)
{
    //Get the path where the file is stored
    string path;
    cout << "Enter The Path To The File: ";
    getline(cin, path);

    //If no path was entered
    if(path == "")
    {
        cout << "\n No Path was entered!" << endl;
        system("pause");
        return;
    }

    //Reads the data from the file
    ifstream data;
    data.open(path.c_str(), ios::in);
    cout << "\nReading Data From " << path <<endl;

    //It creates a DailyData object instance from every line
    //Then it stores that data object in the vector so it can
    //be used during runtime
    string currLine;
    while(getline(data, currLine))
    {
        DailyData curr;
        try
        {
            curr = DailyData(currLine);
        }
        catch(...)
        {
            cout << "\n The data is invalid!" << endl;
            system("pause");
            return;
        }
        dataList.push_back(curr);
    }

    cout << "Done Loading Data From " << path << endl;
    system("pause");
}

//The function perform searches on the "dataList" vector and store them in the "temp" vector
static void SearchData(vector<DailyData>& dataList)
{
    string selection;
    list<DailyData> temp;
    cout << "--------------------------" << endl
         << "1. Search By Date" << endl
         << "2. Search By Day" << endl
         << "3. Search By Month" << endl
         << "4. Search By Year" << endl
         << "5. Search By Rainfall" << endl
         << "--------------------------\n" << endl;

    cout<< "Please select an option from the menu : ";

    getline(cin, selection);

    //Searching by date
    if(selection == "1")
    {
        string day;
        string month;
        string year;

        //Enter the day
        cout << "\nEnter the day: ";
        getline(cin, day);

        //Enter the month
        cout << "\nEnter the month: ";
        getline(cin, month);

        //Enter the year
        cout << "\nEnter the year: ";
        getline(cin, year);

        //Error handling
        try
        {
            //Loops through the data and checks the date
            for(int i = 0; i < dataList.size(); i++)
            {
                if (dataList[i].day == stoi(day))
                    if (dataList[i].month == stoi(month))
                        if (dataList[i].year == stoi(year))
                        {
                            //prints the date if found
                            dataList[i].Summary();
                            temp.push_back(dataList[i]);
                        }
            }
        }
        catch(...)
        {
            cout << "\n Invalid Date Entered" << endl;
        }
    }
    //Searching by day
    else if(selection == "2")
    {
        string day;
        cout << "\nEnter the day: ";
        getline(cin, day);

        try
        {
            for(int i = 0; i < dataList.size(); i++)
            {
                if (dataList[i].day == stoi(day))
                {
                    dataList[i].Summary();
                    temp.push_back(dataList[i]);
                }
            }
        }
        catch(...)
        {
            cout << "\n Invalid Day Entered" << endl;
        }
    }
    //Search by month
    else if(selection == "3")
    {
        string month;
        cout << "\nEnter the month: ";
        getline(cin, month);

        try
        {
            for(int i = 0; i < dataList.size(); i++)
            {
                if (dataList[i].month == stoi(month))
                {
                    dataList[i].Summary();
                    temp.push_back(dataList[i]);
                }
            }
        }
        catch(...)
        {
            cout << "\n Invalid Month Entered" << endl;
        }
    }
    //Searching By year
    else if(selection == "4")
    {
        string year;
        cout << "\nEnter the year: ";
        getline(cin, year);

        try
        {
            //Searching by day
            for(int i = 0; i < dataList.size(); i++)
            {
                if (dataList[i].year == stoi(year))
                {
                    dataList[i].Summary();
                    temp.push_back(dataList[i]);
                }
            }
        }
        catch(...)
        {
            cout << "\n Invalid Year Entered" << endl;
            system("pause");
        }
    }
    //Searching by rainfall
    else if(selection == "5")
    {
        string rain;
        cout << "Checking to see the days it rained: ";
        try
        {
            for(int i = 0; i < dataList.size(); i++)
            {
                if (dataList[i].meltedRain > 0)
                {
                    temp.push_back(dataList[i]);
                }
            }

            for(auto data: temp)
            {
            	data.print();
            }
        }
        catch(...)
        {
            cout << "\n An Error Occurred!" << endl;
        }
    }
    else
    {
        cout << "Invalid Option" << endl;
        return;
    }

    if (temp.size() == 0)
    {
        cout << "No data has been found!" << endl;
    }

    system("pause");
    temp.clear();
}

//Performs a bubble sort on the vector that is passed into it
void SortData(vector<DailyData>& dataList)
{
    //Standard menu things
    string selection;
    cout << "------------------------------------------" << endl;
    cout << "1. Sort Temperature From Highest To Lowest" << endl;
    cout << "2. Sort Temperature From Lowest To Highest" << endl;
    cout << "3. Sort Rainfall From Lowest To Highest" << endl;
    cout << "4. Sort Rainfall From Highest To Lowest" << endl;
    cout << "------------------------------------------" << endl;

    cout<< "Please select an option from the menu : ";

    getline(cin, selection);

    //If there is only 1 element in the vector, then there is nothing to sort
    if(dataList.size() == 1)
    {
        return;
    }

    if(selection == "1")
    {
        //This is to keep track if the list was sorted or not
        bool swapped;

        //A Do-While Loop
        //If the array has not been fully sorted, it does the sorting process again
        do
        {

            swapped = false;
            //This goes through all items on the list comparing them with adjacent ones
            for(int i = 0; i < dataList.size(); i++)
            {
                try
                {
                    //The condition by which to sort items is given here
                    if (dataList[i].avgTemp() < dataList[i+1].avgTemp())
                    {
                        //This swaps 2 adjacent items on the list
                        std::swap(dataList[i], dataList[i+1]);

                        //This is set to true if an item was sorted
                        //If no item was sorted, it means the whole list has been sorted and then it exits
                        swapped = true;
                    }
                }
                catch(...)
                {
                    cout <<"An Error Occurred" <<endl;
                }
            }
        }
        while(swapped == true);
        //If the no swap occurred after trying to sort the list, it means the list has been sorted
    }
    else if(selection == "2")
    {
        bool swapped;
        do
        {
            swapped = false;
            for(int i = 0; i < dataList.size(); i++)
            {
                try
                {
                    if (dataList[i].avgTemp() > dataList[i+1].avgTemp())
                    {
                        std::swap(dataList[i], dataList[i+1]);
                        swapped = true;
                    }
                }
                catch(...)
                {
                    cout <<"An Error Occurred" <<endl;
                }
            }
        }
        while(swapped == true);
    }
    else if(selection == "3")
    {
        bool swapped;
        do
        {
            swapped = false;
            for(int i = 0; i < dataList.size(); i++)
            {
                try
                {
                    if (dataList[i].meltedRain > dataList[i+1].meltedRain)
                    {
                        std::swap(dataList[i], dataList[i+1]);
                        swapped = true;
                    }
                }
                catch(...)
                {
                    cout <<"An Error Occurred" <<endl;
                }
            }
        }
        while(swapped == true);
    }
    else if(selection == "4")
    {
        bool swapped;
        do
        {
            swapped = false;
            for(int i = 0; i < dataList.size(); i++)
            {
                try
                {
                    if (dataList[i].meltedRain < dataList[i+1].meltedRain)
                    {
                        std::swap(dataList[i], dataList[i+1]);
                        swapped = true;
                    }
                }
                catch(...)
                {
                    cout <<"An Error Occurred" <<endl;
                }
            }
        }
        while(swapped == true);
    }
    else
    {
        cout << "Invalid Selection" << endl;
    }

    //A For-Loop that goes through the dataList vector and prints every element
    for(auto data: dataList)
    {
        data.print();
    }
}

