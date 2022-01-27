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
#ifndef EXCEPTION
#define EXCEPTION
#include <exception>
#endif
#ifndef PARSER_HPP
#define PARSER_HPP
#include "parser.hpp"
#endif

using namespace std;

/**
 * @brief Read the data in using a parser and place each element in a vector<string>. Headers are placed in a class called "Data_Headers".
 * All other data is placed in a vector<vector<string>> of elements in a class called "Data_Rows". Finally, a third class, Row_Keys, is used to make a 
 * final vector<string> of all the Incident Numbers (generically speaking, the first column of each row). These are all placed in a Data_Bundle bundle and returned.
 * 
 * @param bundle class that holds all the various classes associated with a read CSV.
 * @param fname string of the csv file's location.
 * @return Data_Bundle bundle of all data from the CSV as well as the Row_Keys.
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