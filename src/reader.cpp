/**
 * @file reader.cpp
 * @author Kristopher Houston - 041015388
 * @brief Reads a .csv file and places the data therein into working memory in the form of a data_bundle
 * @version 2.0
 * @date 2022-02-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ALGORITHM
#define ALGORITHM
#include <algorithm>
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
#ifndef DISPLAY_CPP
#define DISPLAY_CPP
#include "display.cpp"
#endif
#ifndef DATA_CPP
#define DATA_CPP
#include "Data.cpp"
#endif
#ifndef PARSER_HPP
#define PARSER_HPP
#include "./libraries/parser.hpp"
#endif
#ifndef EXCEPTION
#define EXCEPTION
#include <exception>
#endif

using namespace std;

/**
 * @brief Calls a 3rd pary reader (parser.hpp) and uses it to populate the data_bundle object passed in
 * 
 * @param bundle bundle of all data types to be written to
 * @param fname name of the file to be read into the data bundle
 * @return Data_Bundle 
 */
Data_Bundle reader(Data_Bundle bundle, string fname)
{
    ifstream file(fname);
    if (file.is_open())
    {
        aria::csv::CsvParser parser = aria::csv::CsvParser(file)
                                          .delimiter(',')
                                          .quote('"')
                                          .terminator('\n');

        vector<vector<string>> content;
        vector<string> record;
        string buffer;
        int i = 0;

        for (auto &row : parser)
        {
            for (auto &field : row)
            {
                record.push_back(field);
            }
            if (i > 0) // if the row number is over 0, add it to content and clear record for new line
            {
                content.push_back(record);
                record.clear();
            }
            else // otherwise, create the column header object and clear the record for a new line.
            {
                bundle.data_headers.setColumn_headers(record);
                record.clear();
            }
            i++;
        }

        bundle.data_rows.setColumn_data(content); // write the rest of the data to the Column_data object

        record.clear();

        for (int i = 0; i < content.size(); i++)
        {
            record.push_back(content[i][0]);
        }
        bundle.row_keys.setIncident_numbers(record);
        record.clear(); // get rid of the extra data.

        return bundle;
    }
    else
    {
        throw Read_Exception();
        return bundle;
    }
}