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

const static int GRAPHSTARS = 114;
const static string X_AXIS = "*          |---------|---------|---------|---------|---------|---------|---------|---------|---------|---------| *\n*                   10        20        30        40        50        60        70        80        90       100 *\n";
const static string X_LABEL = "*                                                   Percent(%)                                                   *\n";
const static string BUFFER = "*                                                                                                                *"; // No new line here (sub for endl in output)
const static string BOTTOM_EDGE = "******************************************************************************************************************\n";

string generateKey(string title, map<int, string> totals);
string generateGraphVal(string name, int value, int total);
string generateTitle(string title, int const numstars);

void graphDisplay(map<int, string> totals, string title, int numRecords)
{
    bool makeKey = false; // master check to see if a key needs to be made
    string key;
    map<int, string>::iterator it;
    string graphedValues;
    int counter = 0;
    string titleString;
    
    title = " " + title + " ";
    titleString = generateTitle(title, GRAPHSTARS);
    titleString += BUFFER;
    cout << "\n"
         << titleString << endl;
    for (it = totals.begin(); it != totals.end(); it++) // check if anything is longer than 8 chars
    {
        if (!makeKey && it->second.length() > 8) // if it's longer than 8 characters, then set makeKey to true
        {
            makeKey = true;
        }
    }

    if (makeKey) // if makeKey is true, make all legend values into a hash
    {
        key = generateKey(title, totals);
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
    // outer 2 stars and a space before/after [4], 8 for labels, 1 for space and one for '|' [2], 100 for the data
    // cout << "******************************************************************************************************************\n" // 114
    //      << "*" << title << "\n";

    cout << graphedValues << X_AXIS << X_LABEL << BUFFER << "\n"
         << BOTTOM_EDGE << endl;
    cout << key;
}

/**
 * @brief Generate the key portion of a graph
 *
 * @param totals map of the values being graphed
 * @return string containing the formatted key
 */
string generateKey(string title, map<int, string> totals)
{
    title = " Key: " + title + " ";
    map<int, string>::iterator it;
    int counter = 0;
    string key;
    string assemble = "";
    int ltemp = 0;
    for (it = totals.begin(); it != totals.end(); it++)
    {
        // Make formatted string and figure out which one is longest
        key = "* " + to_string(counter) + ": " + it->second + " -- total: " + to_string(it->first) + " *";
        if (ltemp < key.size())
        {
            ltemp = key.size();
        }
        counter++;
        key.clear();
    }
    key = generateTitle(title, ltemp);
    // Add buffer line - This is technically dupilicate code
    key += "*";
    for (int i = ltemp; i > 2; i--)
    {
        key += " ";
    }
    key += "*\n";
    counter = 0;
    for (it = totals.begin(); it != totals.end(); it++)
    {
        assemble = "* " + to_string(counter) + ": " + it->second + " -- total: " + to_string(it->first);
        for (int i = assemble.size(); i < (ltemp - 1); i++)
        {
            assemble += " ";
        }
        assemble += "*\n";
        key += assemble;
        counter++;
    }
    // Add buffer line
    key += "*";
    for (int i = ltemp; i > 2; i--)
    {
        key += " ";
    }
    key += "*\n";
    for (int i = ltemp; i > 0; i--)
    {
        key += "*";
    }
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
    // convert ints to floats
    float fvalue = (float)value;
    float ftotal = (float)total;

    string formatted = "* ";
    int remainder = (8 - name.length());
    for (; remainder > 0; remainder--)
    {
        formatted += " "; // add a blank space
    }
    formatted += name + " |";
    float rd = (100.0 - ((fvalue / ftotal) * 100.0)); // The .0 is REALLY important - otherwise, the compiler discards the float and treats as INT!
    remainder = round(rd);
    for (int i = remainder; i < 100; i++)
    {
        formatted += "]";
    }
    for (; remainder > 0; remainder--)
    {
        formatted += " ";
    }
    // data now finished
    formatted += " *\n"; // final space and edge of container
    return formatted;
}

string generateTitle(string title, int const numstars)
{
    string genTitle;
    int stars = numstars;
    stars -= title.size();
    stars = stars / 2;
    for (int i = 0; i < stars; i++)
    {
        genTitle += "*";
    }
    genTitle += title;
    for (int i = genTitle.size(); i < numstars; i++)
    {
        genTitle += "*";
    }
    genTitle += "\n";
    return genTitle;
}