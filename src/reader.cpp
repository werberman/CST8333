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
using namespace std;

Data_Bundle reader (string fname) 
{
    vector<vector<string>> content;
    vector<string> row;
    string line, word;


    vector<string> incidentNoVector;

    fstream file(fname, ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout << "Could not open the file\n";

    // Place the header information in a struct, then remove it from the vector
    Data_Headers colHeader;
    colHeader.column_headers = content[0];
    content.erase(content.begin());

    // Place the row data in a struct.
    Data_Rows allData;
    allData.column_data = content;

    Row_Key incidentNumbers;
    for (int i = 0; i < allData.column_data.size(); i++)
    {
        incidentNoVector.push_back(allData.column_data[i][0]);
    }
    incidentNumbers.incident_numbers = incidentNoVector;

    Data_Bundle bundle;
    bundle.data_headers = colHeader;
    bundle.data_rows = allData;
    bundle.row_keys = incidentNumbers;

    return bundle;
}