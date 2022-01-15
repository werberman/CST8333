#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/**
 * @brief 
 * 
 * @param fname 
 * @return Data_Bundle 
 */
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
    colHeader.setColumn_headers(content[0]);
    content.erase(content.begin());

    // Place the row data in a struct.
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