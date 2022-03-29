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

void tabulate(vector<string> raw);

using namespace std;
void genStats(Data_Bundle bundle)
{
    vector<string> rawDates;
    int numRecords = bundle.row_keys.getIncident_numbers().size();

    // get number of incidents in each year
    for (int i = 0; i < bundle.row_keys.getIncident_numbers().size(); i++)
    {
        rawDates.push_back(bundle.data_rows.getColumn_data()[i][14]);
    }
    tabulate(rawDates);
}

void tabulate(vector<string> raw)
{
    vector<string> fp;
    vector<string> sp;
    map<int, string> totals;
    for (int i = 0; i < raw.size(); i++)
    {
        fp.push_back(raw[i].substr(0, 4));
    }
    sp = fp;
    sort(sp.begin(), sp.end());

    sp.erase(unique(sp.begin(), sp.end()), sp.end());
    sp.erase(sp.begin()); // remove the empty element left in the front

    cout << sp.size(); // Hmmm, this gives the wrong number by +1... -- empty value is at the start (0 is undefined) - see above.

    string val = "2008";

    for (int i = 0; i < sp.size(); i++) // get each unique value and figure out how many there are of each
    {
        totals.insert(pair<int, string>((count(fp.begin(), fp.end(), sp[i])), sp[i]));
    }

    map<int, string>::iterator it;
    for (it = totals.begin(); it != totals.end(); it++)
    {
        cout << it->second << " " << it->first << " | ";
    }
    cout << endl;
    //  int freq = std::count(fp.begin(), fp.end(), val);

    //      for (int i = 0; i < sp.size(); i++)
    // {
    //     cout << "Loop no: " << i << "\n";
    //     cout << "SP no: " << sp[i] << "\n";
    // }

    // std::cout << "Element " << val << " occurs " << freq << " times";
    return;
}