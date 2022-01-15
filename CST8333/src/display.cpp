#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

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

/**
 * @brief prompt the user for the number of records they would like displayed.
 *
 */
void displaySelectedNoRecords()
{
    cout << "Select the number of records to display: ";
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
