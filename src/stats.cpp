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


map<int, string> tabulate(vector<string> raw);
void displayStats(map<int, string> totals);

using namespace std;
void genStats(Data_Bundle bundle)
{
    vector<string> rawDates;
    vector<string> fDates;
    vector<string> rawReleaseType;
    map<int, string> dateStats;
    map<int, string> releaseTypeStats;
    int numRecords = bundle.row_keys.getIncident_numbers().size();

    // get number of incidents in each year
    for (int i = 0; i < bundle.row_keys.getIncident_numbers().size(); i++)
    {
        rawDates.push_back(bundle.data_rows.getColumn_data()[i][14]);
        rawReleaseType.push_back(bundle.data_rows.getColumn_data()[i][10]);
    }
    for (int i = 0; i < rawDates.size(); i++)
    {
        fDates.push_back(rawDates[i].substr(0, 4));
    }
    dateStats = tabulate(fDates);
    releaseTypeStats = tabulate(rawReleaseType); // figure out why this doesn't work as an optional field
    displayStats(releaseTypeStats);
    displayStats(dateStats);
    graphDisplay(dateStats, TITLE_DATE, numRecords);
    graphDisplay(releaseTypeStats, TITLE_TYPE, numRecords);
}

map<int, string> tabulate(vector<string> raw)
{
    vector<string> sp;
    map<int, string> totals;

    sp = raw;

    sort(sp.begin(), sp.end());                       // sort the array first so unique can clear out repeated values
    sp.erase(unique(sp.begin(), sp.end()), sp.end()); // Hmmm, this gives the wrong number by +1... -- empty value is at the start (0 is undefined) - see below.
    sp.erase(sp.begin());                             // remove the empty element left in the front

    for (int i = 0; i < sp.size(); i++) // get each unique value and figure out how many there are of each
    {
        totals.insert(pair<int, string>((count(raw.begin(), raw.end(), sp[i])), sp[i]));
    }

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