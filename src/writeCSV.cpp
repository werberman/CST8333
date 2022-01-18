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
#ifndef DATA_CPP
#define DATA_CPP
#include "Data.cpp"
#endif

/**
 * @brief NOT WORKING
 *
 * @param bundle
 * @return true
 * @return false
 */
string writeCSV(Data_Bundle bundle)
{

    std::string csv;
    int numRecords = bundle.data_rows.getColumn_data().size();
    std::cout << "numRecords: "
              << numRecords;
    // Add each column header to the string and seperate them with a comma
    for (int i = 0; i < bundle.data_headers.getColumn_headers().size(); i++)
    {
        csv.append(bundle.data_headers.getColumn_headers()[i]);
        csv.append(",");
    }
    csv.append("\n"); // End the line with a carrage return.
    std::cout << "DEBUG - finished writing headers to string";

    // Add each element of each record to the string and seperate them with a comma
    for (int i = 0; i < bundle.data_headers.getColumn_headers().size(); i++)
    {
        for (int j = 0; j < bundle.data_rows.getColumn_data().size(); j++)
        {
            csv.append(bundle.data_rows.getColumn_data()[i][j]);
            csv.append(",");
        }
        csv.append("\n"); // End each row with a carrage return
    }

    return csv;
}