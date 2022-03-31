#ifndef DATA_CPP
#define DATA_CPP
#include "Data.cpp"
#endif
#ifndef DISPLAY_CPP
#define DISPLAY_CPP
#include "display.cpp"
#endif
#ifndef ALGORITHM
#define ALGORITHM
#include <algorithm>
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef VECTOR
#define VECTOR
#include <vector>
#endif
#ifndef MAP
#define MAP
#include <map>
#endif
#ifndef GRAPHICSDISPLAY_CPP
#define GRAPHICSDISPLAY_CPP
#include "./graphics/graphicsdisplay.cpp"
#endif

const static string TITLE_MISSING = "N/A";

map<int, string> tabulate(vector<string> raw);
void displayStats(map<int, string> totals);

using namespace std;

void debug(vector<string> disp)
{
    for (int i = 0; i < disp.size(); i++)
    {
        cout << "DEBUG: vector element " << to_string(i) << ": " << disp[i] << "\n";
    }
}

void genStats(Data_Bundle bundle, int colNo)
{
    vector<string> rawData;
    vector<string> fData;
    map<int, string> mappedData;

    int numRecords = bundle.row_keys.getIncident_numbers().size();

    // get number of incidents in each year
    for (int i = 0; i < bundle.row_keys.getIncident_numbers().size(); i++)
    {
        if (bundle.data_rows.getColumn_data()[i][colNo] != "")
        {
        rawData.push_back(bundle.data_rows.getColumn_data()[i][colNo]);
        }
        else 
        {
            rawData.push_back(TITLE_MISSING);
        }
    }

    mappedData = tabulate(rawData);
    displayStats(mappedData);

    graphDisplay(mappedData, bundle.data_headers.getColumn_headers()[colNo], numRecords);
}

/**
 * @brief SOMETHING IS NOT WORKING HERE - gives the wrong number of values, no idea why
 *
 * @param raw
 * @return map<int, string>
 */
map<int, string> tabulate(vector<string> raw)
{
    vector<string> sp;
    map<int, string> totals;
    int counter = 0; // DEBUG ONLY

    sp = raw;

    sort(sp.begin(), sp.end());                       // sort the array first so unique can clear out repeated values
    sp.erase(unique(sp.begin(), sp.end()), sp.end()); // Hmmm, this gives the wrong number by +1... -- empty value is at the start (0 is undefined) - see below.
    // sp.erase(sp.begin());                             // remove the empty element left in the front

    for (int i = 0; i < sp.size(); i++) // get each unique value and figure out how many there are of each
    {
        totals.insert(pair<int, string>((count(raw.begin(), raw.end(), sp[i])), sp[i]));
        counter++;
    }
    cout << "DEBUG: counter = " << to_string(counter) << "\n";
    debug(sp);
    displayStats(totals);
    return totals;
}

void displayStats(map<int, string> totals)
{
    map<int, string>::iterator it;
    for (it = totals.begin(); it != totals.end(); it++)
    {
        cout << it->second << " " << it->first << " | ";
    }
    cout << endl;
}