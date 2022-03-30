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

const static string TITLE_DATE = "Date of Occurance";
const static string TITLE_TYPE = "Substance Spilled";
const static string TITLE_SIGNIFICANT = "Significant?";
const static string TITLE_STATE = "Type of Substance";

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

void genStats(Data_Bundle bundle)
{
    vector<string> rawDates;
    vector<string> fDates;
    vector<string> rawReleaseType;
    vector<string> rawSignificiant;
    vector<string> rawReleaseState;
    map<int, string> dateStats;
    map<int, string> releaseTypeStats;
    map<int, string> releaseStateStats;
    map<int, string> significantStats;

    int numRecords = bundle.row_keys.getIncident_numbers().size();

    // get number of incidents in each year
    for (int i = 0; i < bundle.row_keys.getIncident_numbers().size(); i++)
    {
        rawDates.push_back(bundle.data_rows.getColumn_data()[i][14]);
        rawReleaseType.push_back(bundle.data_rows.getColumn_data()[i][10]);
        rawReleaseState.push_back(bundle.data_rows.getColumn_data()[i][11]);
        rawSignificiant.push_back(bundle.data_rows.getColumn_data()[i][12]);
    }
    for (int i = 0; i < rawDates.size(); i++)
    {
        if (rawDates[i] != "")
        {
            fDates.push_back(rawDates[i].substr(0, 4));
        }
        else
        {
            fDates.push_back(bundle.data_rows.getColumn_data()[i][13]);
        }
    }
    dateStats = tabulate(fDates);
    releaseTypeStats = tabulate(rawReleaseType); // figure out why this doesn't work as an optional field
    releaseStateStats = tabulate(rawReleaseState);
    significantStats = tabulate(rawSignificiant);
    displayStats(releaseTypeStats);
    displayStats(dateStats);
    displayStats(significantStats);
    displayStats(releaseStateStats);
    cout << "DEBUG: rawDates = " << to_string(rawDates.size()) << " , Bundle = " << to_string(bundle.row_keys.getIncident_numbers().size())
         << ", fdates = " << to_string(fDates.size()) << "\n";
    graphDisplay(dateStats, TITLE_DATE, numRecords);
    graphDisplay(releaseTypeStats, TITLE_TYPE, numRecords);
    graphDisplay(significantStats, TITLE_SIGNIFICANT, numRecords);
    graphDisplay(releaseStateStats, TITLE_STATE, numRecords);
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