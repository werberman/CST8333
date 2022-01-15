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
         << "5) Save as a new CSV file\n";
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

void displayReloadCSV()
{
    cout << "DEBUG: THIS IS THE displayReloadCSV Function";
};