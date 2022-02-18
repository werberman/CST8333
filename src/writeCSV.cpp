/**
 * @file writeCSV.cpp
 * @author Kristopher Houston - 041015388
 * @brief write a data_bundle to a new file
 * @version 0.1
 * @date 2022-02-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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
#ifndef EXCEPTION
#define EXCEPTION
#include <exception>
#endif

/**
 * @brief Write the csv data in memory to a new csv file - TODO: Fix the performance issues reading and writing.
 * 
 * @param bundle the bundled records stored in memory
 * @param newFileName desired name for the new CSV file
 */
void writeCSV(Data_Bundle bundle, string newFileName)
{
    ofstream newFile;

    try // handle if the file cannot be written for any reason.
    {
        newFile.open(newFileName);
    }
    catch (...) // Has to be a catch all since .open doesn't return anything
    {
        throw Write_Exception();
        return;
    }

    int numRecords = bundle.data_rows.getColumn_data().size();

    // Add each column header to the string and seperate them with a comma
    for (int i = 0; i < bundle.data_headers.getColumn_headers().size(); i++)
    {
        newFile << "\"";
        newFile << bundle.data_headers.getColumn_headers()[i];
        newFile << "\"";
        if (i < (bundle.data_headers.getColumn_headers().size() - 1)) // don't add a comma if it's the last value in the row
        {
            newFile << ",";
        }
        else
        {
            newFile << "\n"; // End the line with a carrage return.
        }
    }

    // Add each element of each record to the string and seperate them with a comma
    for (int i = 0; i < bundle.data_rows.getColumn_data().size(); i++)
    {
        for (int j = 0; j < bundle.data_rows.getColumn_data()[0].size(); j++)
        {
            newFile << "\"";
            newFile << bundle.data_rows.getColumn_data()[i][j];
            newFile << "\"";
            if (j < (bundle.data_rows.getColumn_data()[0].size() - 1))
            {
            newFile << ","; // Add a comma after each record
            }
            else
            {
                newFile << "\n"; // End each row with a carrage return
            }
        }
    }
    newFile.close(); // Close the file when finished writing
}