#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#ifndef DATA_CPP
#define DATA_CPP
#include "Data.cpp"
#endif

/**
 * @brief 
 * 
 * @param bundle 
 * @return true 
 * @return false 
 */
bool writeCSV(Data_Bundle bundle)
{
    std::string csv;

    for (int i = 0; i < bundle.data_headers.column_headers.size(); i++)
    {
        csv.append(bundle.data_headers.column_headers[i]);
        csv.append(",");
    }
    csv.append("\n");

    for (int i = 0; i < bundle.data_rows.column_headers[].size(); i++) //Hmmmm...how will this work?
    {

    }
}