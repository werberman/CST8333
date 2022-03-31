#ifndef MAP
#define MAP
#include <map>
#endif
#ifndef STRING
#define STRING
#include <string>
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef VECTOR
#define VECTOR
#include <vector>
#endif

using namespace std;
/**
 * @brief A mostly debug function built to show the contents of a map<int, string>
 * 
 * @param totals a map of statistical totals (must be formatted correctly - see genStats())
 */
void displayStats(map<int, string> totals)
{
    map<int, string>::iterator it;
    for (it = totals.begin(); it != totals.end(); it++)
    {
        cout << it->second << " " << it->first << " | ";
    }
    cout << endl;
}

/**
 * @brief A debug method to output the contents of a vector
 * 
 * @param disp 
 */
void debug(vector<string> disp)
{
    for (int i = 0; i < disp.size(); i++)
    {
        cout << "DEBUG: vector element " << to_string(i) << ": " << disp[i] << "\n";
    }
}