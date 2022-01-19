#ifndef DATA_CPP
#define DARTA_CPP
#include "Data.cpp"
#endif
#ifndef READER_CPP
#define READER_CPP
#include "reader.cpp"
#endif
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

int main()
{
    int m;
    string fname = "C:/Sjunk/C++/pipeline-incidents-comprehensive-data.csv";

    Data_Bundle bundle;

    bundle = reader(fname);
    
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