#ifndef DATA_CPP
#define DARTA_CPP
#include "Data.cpp"
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
#ifndef EXCEPTION
#define EXCEPTION
#include <exception>
#endif
#ifndef READER_CPP
#define READER_CPP
#include "reader.cpp"
#endif

using namespace std;

/**
 * @brief Load the given file and ask the user how many records they wish to display. Only
 * displays the first 5 fields of each record.
 *
 * @return int 0 when finished.
 */
int main()
{
    int m;
    string fname = "C:/Sjunk/C++/pipeline-incidents-comprehensive-data.csv";
    Data_Bundle bundle;

    try
    {
        bundle = reader(bundle, fname);
    }
    catch (Read_Exception &e1)
    {
        cout << "Could not open the file!";
        return 0;
    }

    // try
    // {
    //     bundle = reader(fname);
    // }
    // catch (Read_Exception &e1)
    // {
    //     cout << "Could not open file\n";
    //     return 0;
    // }

    cout << "Select the number of records to display: ";
    cin >> m;
    cout << "\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "*******************************\n"
             << bundle.data_headers.getColumn_headers()[i] << " : \n";
        for (int j = 0; j < m; j++)
        {
            cout << "Record No: " << (j + 1) << ": " << bundle.data_rows.getColumn_data()[j][i] << endl;
        }
    }

    cout << "\nBy: Kristopher Houston\nStudent No: 041015388\nCST8333\nWinter, 2022";

    return 0;
}