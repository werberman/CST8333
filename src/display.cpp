/**
 * @file display.cpp
 * @author Kristopher Houston - 041015388
 * @brief Handles all user output and input. If it's user I/O related, it should be in here.
 * @version 0.1
 * @date 2022-02-18
 *
 * @copyright Copyright (c) 2022
 *
 */
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
#ifndef MAP
#define MAP
#include <map>
#endif
#ifndef CMATH
#define CMATH
#include <cmath>
#endif

// TODO: Consider moving menues into consts here

using namespace std;

string generateKey(map<int, string> totals);
string generateGraphVal(string name, int value, int total);

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
 * @brief get a menu selection from a user and verify that it is an alphabetical character. If input was NOT
 * an alphabetical character, it returns 'z'.
 *
 * @return char either 'z' in case of invalid input, or else whatever the user input.
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

/**
 * @brief get input from the user (string)
 *
 * @return string input from the user
 */
string stringInput()
{
    string input;
    std::cin >> input;
    return input;
}

void graphDisplay(map<int, string> totals, string title)
{
    genericMessage("graphDisplay begin!");
    bool makeKey = false; // master check to see if a key needs to be made
    string key;
    map<int, string>::iterator it;
    string graphedValues;
    int counter = 0;
    int total;

    for (it = totals.begin(); it != totals.end(); it++) // check if anything is longer than 8 chars
    {
        total += it->first;                      // add all the values together
        if (it->second.length() < 8 && !makeKey) // if it's longer than 8 characters, then set makeKey to true
        {
            makeKey = true;
        }
    }

    if (makeKey) // if makeKey is true, make all legend values into a hash
    {
        key = generateKey(totals);

        for (it = totals.begin(); it != totals.end(); it++)
        {
            // Make formatted string
            graphedValues += generateGraphVal("Key: " + counter, it->first, total);
            // cout << it->second << " " << it->first << " | ";
            counter++;
        }
    }
    else
    {
        for (it = totals.begin(); it != totals.end(); it++)
        {
            graphedValues += generateGraphVal(it->second, it->first, total);
        }
    }
    // have a key - max length: 8 char ("Key: 999")
    // outer 2 stars and a space before/after, 8 for labels, 1 for space and one for '|', 100 for the data
    // cout << "******************************************************************************************************************\n" // 114
    //      << "*" << title << "\n";

    cout << graphedValues;
}

/**
 * @brief Generate the key portion of a graph
 *
 * @param totals map of the values being graphed
 * @return string containing the formatted key
 */
string generateKey(map<int, string> totals)
{
    string key = "";
    return key;
}

/**
 * @brief
 *
 * @param name
 * @param value
 * @param total
 * @return string
 */
string generateGraphVal(string name, int value, int total)
{
    string formatted = "* ";
    int remainder = (8 - name.length());
    for (; remainder < 8; remainder++)
    {
        formatted += " "; // add a blank space
    }
    formatted += name + " |";
    double rd = (100 - (value / total));
    remainder = round(rd);
    for (int i = remainder; i > 0; i--) // this SUBTRACTS, does not add
    {
        formatted += "]";
    }
    for (; remainder < 100; remainder++)
    {
        formatted += " ";
    }
    // data now finished
    formatted += " *\n"; // final space and edge of container
    return formatted;
}