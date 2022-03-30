#ifndef MAP
#define MAP
#include <map>
#endif
#ifndef CMATH
#define CMATH
#include <cmath>
#endif
#ifndef DISPLAY_CPP
#define DISPLAY_CPP
#include "./src/display.cpp"
#endif

using namespace std;

string generateKey(map<int, string> totals);
string generateGraphVal(string name, int value, int total);

void graphDisplay(map<int, string> totals, string title, int numRecords)
{
    bool makeKey = false; // master check to see if a key needs to be made
    string key;
    map<int, string>::iterator it;
    string graphedValues;
    int counter = 0;

    for (it = totals.begin(); it != totals.end(); it++) // check if anything is longer than 8 chars
    {
        if (!makeKey && it->second.length() > 8) // if it's longer than 8 characters, then set makeKey to true
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
            graphedValues += generateGraphVal("Key: " + to_string(counter), it->first, numRecords);
            // cout << it->second << " " << it->first << " | ";
            counter++;
        }
    }
    else
    {
        for (it = totals.begin(); it != totals.end(); it++)
        {
            graphedValues += generateGraphVal(it->second, it->first, numRecords);
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
    cout << "\nTEMP DEBUG: GenerateKey triggered!\n";
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
    //convert ints to floats
    float fvalue = (float)value;
    float ftotal = (float)total;

    string formatted = "* ";
    int remainder = (8 - name.length());
    for (; remainder < 8; remainder++)
    {
        formatted += " "; // add a blank space
    }
    formatted += name + " |";
    float rd = (100.0 - ((fvalue / ftotal)*100.0));//The .0 is REALLY important - otherwise, the compiler discards the float and treats as INT!
    remainder = round(rd);
    cout << "DEBUG: float rd = " << rd << ", remainder int = " << remainder << "\n";
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