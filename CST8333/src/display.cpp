#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void shamelessPlug()
{
    cout << "\nBy: Kristopher Houston\nStudent No: 041015388\nCST8333\nWinter, 2022";
};

/**
 * @brief display the main menu selection options and wait.
 *
 */
void mainMenu()
{
    cout << "Please select one fo the following options: \n"
         << "1) Reload the csv file\n"
         << "2) Display records\n"
         << "3) Add a record\n"
         << "4) Remove a record\n"
         << "5) Save as a new CSV file\n"
         << "6) Review current Incident Numbers\n"
         << "0) Exit program\n";
};

void displayRecMenu()
{
    cout << "\nPlease select one of the following:\n"
         << "1) Display selected number of records starting from any point in the data\n"
         << "2) Search for a specific record by Incident Number\n";
};

/**
 * @brief Display invalid menu selection prompt
 *
 */
void invalidInput()
{
    cout << "Invalid selection. Please try again.\n";
};

void genericMessage(string message)
{
    cout << message;
};

//********************************************************************************
/*Inputs (move to its own file)*/

/**
 * @brief
 *
 * @return int
 */
int menuSelectionInt()
{
    int i;
    std::cin >> i;
    return i;
};

/**
 * @brief
 *
 * @return char
 */
char menuSelectionChar()
{
    char i;
    std::cin >> i;
    return i;
}

string stringInput()
{
    string input;
    std::cin >> input;
    return input;
}

// ********************************************************************************
/*addRemoveRecord Displays*/
