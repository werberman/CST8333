/**
 * @file graphicsdisplay.cpp
 * @author Kristopher Houston - 041015388
 * @brief generate ASCII art graphs using formatted data from stats.cpp
 * @version 1.0
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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
#ifndef FUTURE
#define FUTURE
#include <future>
#endif

using namespace std;

const static int GRAPHSTARS = 121;
const static string X_AXIS = "|          |---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|        |\n|                   10        20        30        40        50        60        70        80        90       100        |\n";
const static string X_LABEL = "|                                                       Percent(%)                                                      |\n";
const static string BUFFER = "|                                                                                                                       |"; // No new line here (sub for endl in output)
const static string BOTTOM_EDGE = "*************************************************************************************************************************\n";

string generateKey(string title, map<int, Stats_Map_Obj> totals, int totalRecords);
string generateGraphVal(string name, int value, int total);
string generateTitle(string title, int const numstars);
/**
 * @brief Generate the graphic display using ASCI art
 *
 * @param totals map of the stats generated (map<int, Stats_Map_Obj>)
 * @param title title to be used for the graph and key
 * @param numRecords toal number of records, so the percent can be generated
 */
void graphDisplay(map<int, Stats_Map_Obj> totals, string title, int numRecords)
{
    future<string> keyGen;
    bool makeKey = false; // master check to see if a key needs to be made
    string key;
    map<int, Stats_Map_Obj>::iterator it;
    string graphedValues;
    string titleString;

    title = " " + title + " ";
    titleString = generateTitle(title, GRAPHSTARS);
    titleString += BUFFER;
    cout << "\n"
         << titleString << endl;
    for (it = totals.begin(); it != totals.end(); it++) // check if anything is longer than 8 chars
    {
        if (!makeKey && it->second.getName().length() > 8) // if it's longer than 8 characters, then set makeKey to true
        {
            makeKey = true;
        }
    }

    if (makeKey) // if makeKey is true, make all legend values into keys
    {
        keyGen = async(generateKey, title, totals, numRecords);
        // key = generateKey(title, totals);
        for (it = totals.begin(); it != totals.end(); it++)
        {
            // Make formatted string
            graphedValues += generateGraphVal("Key: " + to_string(it->first), it->second.getNumber(), numRecords);
        }
    }
    else
    {
        for (it = totals.begin(); it != totals.end(); it++)
        {
            graphedValues += generateGraphVal(it->second.getName(), it->second.getNumber(), numRecords);
        }
    }

    cout << graphedValues << X_AXIS << X_LABEL << BUFFER << "\n"
         << BOTTOM_EDGE << endl;
    try
    {
    key = keyGen.get();
    }
    catch (std::future_error &e1)
    {
        //nothing needs to happen here. Could log it, but I don't have a logger. Not actually an error
    }
    cout << key << endl;
}

/**
 * @brief Generate the key portion of a graph
 *
 * @param totals map of the values being graphed
 * @return string containing the formatted key
 */
string generateKey(string title, map<int, Stats_Map_Obj> totals, int totalRecords)
{
    title = " Key: " + title + " ";
    map<int, Stats_Map_Obj>::iterator it;
    string key;
    string assemble = "";
    int ltemp = 0;
    for (it = totals.begin(); it != totals.end(); it++)
    {
        key = "| " + to_string(it->first) + ": " + it->second.getName() + " -- total: " + to_string(it->second.getNumber()) + " |";
        if (ltemp < key.size())
        {
            ltemp = key.size();
        }
        key.clear();
    }
    key = generateTitle(title, ltemp);
    // Add buffer line - This is technically dupilicate code
    key += "|";
    for (int i = ltemp; i > 2; i--)
    {
        key += " ";
    }
    key += "|\n";
    for (it = totals.begin(); it != totals.end(); it++)
    {
        assemble = "| " + to_string(it->first) + ": " + it->second.getName() + " -- total: " + to_string(it->second.getNumber());
        for (int i = assemble.size(); i < (ltemp - 1); i++)
        {
            assemble += " ";
        }
        assemble += "|\n";
        key += assemble;
    }
    // Add buffer line
    key += "|";
    for (int i = ltemp; i > 2; i--)
    {
        key += " ";
    }
    key += "|\n";
    for (int i = ltemp; i > 0; i--)
    {
        key += "*";
    }
    return key;
}

/**
 * @brief generate the graph values (that is, turn the elements into a string that represents a bar in a larger bar graph)
 *
 * @param name name of the bar being generated
 * @param value value for that bar
 * @param total total number of values in the graph (used to calculate the percentage)
 * @return string of an ASCII bar for a bar graph, fully formatted
 */
string generateGraphVal(string name, int value, int total)
{
    // convert ints to floats
    float fvalue = (float)value;
    float ftotal = (float)total;
    int percent;

    string formatted = "| ";
    int remainder = (8 - name.length());
    for (; remainder > 0; remainder--)
    {
        formatted += " "; // add a blank space
    }
    formatted += name + " |";
    float rd = (100.0 - ((fvalue / ftotal) * 100.0)); // The .0 is REALLY important - otherwise, the compiler discards the float and treats as INT!
    remainder = round(rd);
    percent = (100 - remainder);
    for (int i = remainder; i < 100; i++)
    {
        formatted += "]";
    }
    formatted += " -> ";
    formatted += to_string(percent);
    remainder -= to_string(percent).size();
    // TODO: Check if this breaks if there is a value that makes remainder a negative - if so, add if.
    for (; remainder > 0; remainder--)
    {
        formatted += " ";
    }
    // data now finished
    formatted += "    |\n"; // final space and edge of container
    return formatted;
}

/**
 * @brief Generate the header for a given graph or key
 * 
 * @param title title to embed in the header
 * @param numstars how large the header must be to fit the graph
 * @return string ASCII header for graph or key
 */
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