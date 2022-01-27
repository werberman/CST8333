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

void fileWriter(string line, string newFileName);

/**
 * @brief NOT WORKING - TODO: Make it write each line to the file and clear the buffer rather than make a giant string 
 *
 * @param bundle
 * @return true
 * @return false
 */
string writeCSV(Data_Bundle bundle, string newFileName)
{
    std::string csv = "";
    int numRecords = bundle.data_rows.getColumn_data().size();

    // Add each column header to the string and seperate them with a comma
    for (int i = 0; i < bundle.data_headers.getColumn_headers().size(); i++)
    {
        csv.append(bundle.data_headers.getColumn_headers()[i]);
        if (i < (bundle.data_headers.getColumn_headers().size() - 1)) // don't add a comma if it's the last value in the row
        {
            csv.append(",");
        }
        else
        {
            csv.append("\n"); // End the line with a carrage return.
        }
    fileWriter(csv, newFileName);
    csv.clear();
    }

    // Add each element of each record to the string and seperate them with a comma
    for (int i = 0; i < bundle.data_rows.getColumn_data().size(); i++)
    {
        for (int j = 0; j < bundle.data_rows.getColumn_data()[0].size(); j++)
        {
            csv.append(bundle.data_rows.getColumn_data()[i][j]);
            if (j < (bundle.data_rows.getColumn_data().size() - 1))
            {
                csv.append(",");
            }
            else
            {
                csv.append("\n"); // End each row with a carrage return
            }
        }
    }
    return csv;
}

void fileWriter(string line, string newFileName)
{
    ofstream newFile;

    newFile.open(newFileName);
    newFile << line; // write the string to the new file
    newFile.close();   // close the file
}