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
#ifndef DISPLAY_CPP
#define DISPLAY_CPP
#include "display.cpp"
#endif

/**
 * @brief add a record to the existing records
 *
 * @param bundle current data
 */
Data_Bundle addRecord(Data_Bundle bundle)
{
    Data_Rows newRecord;
    std::vector<std::string> recordVector;

    // Prompt for each field by iterating through the column headers.
    for (int i = 0; i < bundle.data_headers.getColumn_headers().size(); i++)
    {
        std::string currentField = bundle.data_headers.getColumn_headers()[i] + ": ";
        genericMessage(currentField);
        // modify each input to match csv formatting and place in the vector
        recordVector.push_back("\"" + stringInput() + "\"");
    }

    std::vector<vector<std::string>> newRow;
    // Add the new record into the existing data
    newRow = bundle.data_rows.getColumn_data();
    newRow.push_back(recordVector);
    bundle.data_rows.setColumn_data(newRow); // TODO: See if there's a better way to do this.

    std::vector<std::string> newKeys;
    // Add the new record key to the existing keys
    newKeys = bundle.row_keys.getIncident_numbers();
    newKeys.push_back(recordVector[0]);
    bundle.row_keys.setIncident_numbers(newKeys);
    return bundle;
};

/**
 * @brief Delete a record from the exisiting record.
 * NOTE: This does NOT remove the record from the file, just from the working memory. New file must still be written.
 *
 * @param bundle existing data
 */
Data_Bundle removeRecord(Data_Bundle bundle) //TODO NOt working
{
    string input;
    std::vector<vector<std::string>> temp;
    genericMessage("\nWhat is the incident number you wish to remove?: ");
    input = stringInput();
    int index = searchRecords(bundle, input);
    if (index > 0) // if the record is found (searchRecords returns -1 if not found)
    {
        //Consider changing this so it iterates through all the elements in the data and writes them into temp only IF they are
        //not the value to be removed. 
        temp = bundle.data_rows.getColumn_data();
        temp.erase(temp.begin()+index);
        bundle.data_rows.setColumn_data(temp);
    }
    else
    {
        genericMessage("\nUnable to find the record.");
    }
    return bundle;
}