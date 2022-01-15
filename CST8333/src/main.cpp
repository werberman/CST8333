#include "C:/SJunk/C++/CST8333/src/lib/csv.h"
#include "C:/SJunk/C++/CST8333/src/Data.cpp"
#include "C:/Sjunk/C++/CST8333/src/reader.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int m;
    string fname = "C:/Sjunk/C++/pipeline-incidents-comprehensive-data.csv";

    Data_Bundle bundle;

    bundle = reader(fname);
    // vector<vector<string>> content;
    // vector<string> row;
    // string line, word;

    // int m;

    // vector<string> incidentNoVector;

    // fstream file(fname, ios::in);
    // if (file.is_open())
    // {
    //     while (getline(file, line))
    //     {
    //         row.clear();

    //         stringstream str(line);

    //         while (getline(str, word, ','))
    //             row.push_back(word);
    //         content.push_back(row);
    //     }
    // }
    // else
    //     cout << "Could not open the file\n";

    // // Place the header information in a struct, then remove it from the vector
    // Data_Headers colHeader;
    // colHeader.column_headers = content[0];
    // content.erase(content.begin());

    // // Place the row data in a struct.
    // Data_Rows allData;
    // allData.column_data = content;

    // Row_Key incidentNumbers;
    // for (int i = 0; i < allData.column_data.size(); i++)
    // {
    //     incidentNoVector.push_back(allData.column_data[i][0]);
    // }
    // incidentNumbers.incident_numbers = incidentNoVector;


    cout << "Select the number of records to display: ";
    cin >> m;
    cout << "\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "*******************************\n" << bundle.data_headers.column_headers[i] << " : \n";
        for (int j = 0; j < m; j++)
        {
            cout << "Record No: " << (j+1) << ": " << bundle.data_rows.column_data[j][i] << "\n";
        }
    }

    cout << "\nBy: Kristopher Houston\nStudent No: 041015388\nCST8333\nWinter, 2022";

    return 0;
}