#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#ifndef DISPLAY_CPP
#define DISPLAY_CPP
#include "display.cpp"
#endif
#ifndef DATA_CPP
#define DATA_CPP
#include "Data.cpp"
#endif

using namespace std;

/**
 * @brief
 *
 * @param fname
 * @return Data_Bundle
 */
Data_Bundle reader(string fname)
{
    string message = "Loading CSV File...\n";
    genericMessage(message);
    vector<vector<string>> content;
    vector<string> row;
    string line, word, block;

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

    // Place the header information in an object, then remove it from the vector
    Data_Headers colHeader;
    colHeader.setColumn_headers(content[0]);
    content.erase(content.begin());

    // Place the row data in an object.
    Data_Rows allData;
    allData.setColumn_data(content);

    Row_Key incidentNumbers;
    for (int i = 0; i < allData.getColumn_data().size(); i++)
    {
        incidentNoVector.push_back(allData.getColumn_data()[i][0]);
    }
    incidentNumbers.setIncident_numbers(incidentNoVector);

    Data_Bundle bundle;
    bundle.data_headers = colHeader;
    bundle.data_rows = allData;
    bundle.row_keys = incidentNumbers;

    return bundle;
}