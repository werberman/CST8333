#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif
#ifndef STRING
#define STRING
#include <string>
#endif
#ifndef VECTOR
#define VECTOR
#include <vector>
#endif
#ifndef SSTREAM
#define SSTREAM
#include <sstream>
#endif

//TODO: Consider moving menues into consts here

using namespace std;

/**
 * @brief Generic message printer for any string.
 *
 * @param message string to be printed on screen.
 */
void genericMessage(string message)
{
    cout << message << endl;
};

/**
 * @brief Special function to display records:
 * 
 *  Record No 1: This is an example record
 * 
 * @param recordNo the record number to be displayed
 * @param colData string containing the record data to be displayed
 */
void displayRecords(int recordNo, string colData)
{
    cout << "Record No " << recordNo << " : " << colData << endl;
}

/**
 * @brief Place all my student information on screen as required for the assignment.
 *
 */
void shamelessPlug()
{
    genericMessage("\nBy: Kristopher Houston\nStudent No: 041015388\nCST8333\nWinter, 2022");
};

/**
 * @brief Place a banner with all of my student information on screen as required for the assingment.
 * 
 */
void shamelessBanner()
{
    genericMessage("\n***Kristopher Houston***041015388***CST8333***Winter, 2022***");
};

/**
 * @brief display the main menu selection options and wait.
 *
 */
void mainMenu()
{
    shamelessBanner();
    cout << "\nPlease select one of the following options: \n"
         << "1) Reload the csv file\n"
         << "2) Display records\n"
         << "3) Add a record\n"
         << "4) Remove a record\n"
         << "5) Save as a new CSV file\n"
         << "6) Review current Incident Numbers\n"
         << "7) Edit an existing record\n"
         << "0) Exit program\n";
};

/**
 * @brief Display the menu for the display a record menu
 *
 */
void displayRecMenu()
{
    shamelessBanner();
    cout << "\nPlease select one of the following:\n"
         << "1) Display selected number of records starting from any point in the data\n"
         << "2) Search for a specific record by Incident Number\n"
         << "3) Display all records and columns\n"
         << "9) Go back to main menu\n";
};

/**
 * @brief Display invalid menu selection prompt
 *
 */
void invalidInput()
{
    cout << "Invalid selection. Please try again.\n";
};

//********************************************************************************
/*Inputs (move to its own file)*/

/**
 * @brief Get an integer as input. Recieves the input as a string and catches any input that cannot be
 * converted to an int. Returns '999' if a non-int is entered
 *
 * @return int i: the int input by the user. Returns 999 if the user input was not an int.
 */
int menuSelectionInt()
{
    std::string input = "";
    int i;
    std::cin >> input;
    try
    {
        i = stoi(input);
    }
    catch (const std::exception &e)
    {
        return 999;
    }

    return i;
};

/**
 * @brief
 *
 * @return char
 */
char menuSelectionChar()
{
    std::string input = "";
    char i;
    std::cin >> input;
    i = input.at(0);
    if (isalpha(i))
    {
        return i;
    }
    else
    {
        return 'z';
    }
}

string stringInput()
{
    string input;
    std::cin >> input;
    return input;
}