/**
 * @file stats.cpp
 * @author Kristopher Houston - 041015388
 * @brief generate statistics from data_bundle for use with graphicsdisplay.cpp
 * @version 1.0
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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
#ifndef DEBUGGER_H
#define DEBUGGER_H
#include "debugger.h"
#endif

const static string TITLE_MISSING = "N/A";

map<int, Stats_Map_Obj> tabulate(vector<string> raw);

using namespace std;

/**
 * @brief generate statistics for use in graphicsdisplay from a Data_Bundle
 * 
 * @param bundle Data_Bundle - data to be analysed and turned into a graph
 * @param colNo column in the data to be turned into a graph
 */
void genStats(Data_Bundle bundle, int colNo)
{
    vector<string> rawData;
    vector<string> fData;
    map<int, Stats_Map_Obj> mappedData;

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
    graphDisplay(mappedData, bundle.data_headers.getColumn_headers()[colNo], numRecords);
}

/**
 * @brief tabluate the values in the vector and make a map out of them
 *
 * @param raw raw data in the from of a vector<string>
 * @return map<int, string>
 */
map<int, Stats_Map_Obj> tabulate(vector<string> raw)
{
    vector<string> sp;
    map<int, Stats_Map_Obj> totals;

    sp = raw;

    sort(sp.begin(), sp.end()); // sort the array first so unique can clear out repeated values
    sp.erase(unique(sp.begin(), sp.end()), sp.end());

    for (int i = 0; i < sp.size(); i++) // get each unique value and figure out how many there are of each
    {
        Stats_Map_Obj values;
        values.setName(sp[i]);
        values.setNumber(count(raw.begin(), raw.end(), sp[i]));
        totals.insert(pair<int, Stats_Map_Obj>(i, values));
    }
    displayStats(totals);
    return totals;
}
