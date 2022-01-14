#include "C:/SJunk/C++/CST8333/src/lib/csv.h"
#include "C:/SJunk/C++/CST8333/src/Data.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

Data_Headers Reader(string fname) {
    vector<vector<string>> content;
    vector<string> row;
    string line, word;

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

    Data_Headers colHeader;
    colHeader.column_headers = content[0];

    for (int i = 0; i < colHeader.column_headers.size(); i++)
    {
        cout << colHeader.column_headers[i];
    }

    for (int i = 1; i < content.size(); i++)
    {
        Data_Rows 
    }
}