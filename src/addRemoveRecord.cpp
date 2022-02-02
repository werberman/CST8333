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

Data_Bundle removeRecord(Data_Bundle bundle, int index);

/**
 * @brief add a record to the existing records
 *
 * @param bundle current data
 */
Data_Bundle addRecord(Data_Bundle bundle)
{
    std::vector<std::string> recordVector;

    // Prompt for each field by iterating through the column headers.
    for (int i = 0; i < bundle.data_headers.getColumn_headers().size(); i++)
    {
        std::string currentField = bundle.data_headers.getColumn_headers()[i] + ": ";
        genericMessage(currentField);
        // modify each input to match csv formatting and place in the vector
        recordVector.push_back(stringInput());
    }

    std::vector<vector<std::string>> newData;
    // Add the new record into the existing data
    newData.push_back(recordVector); //put the new record in first.
    for (int i = 0; i < bundle.data_rows.getColumn_data().size(); i++)
    {
        newData.push_back(bundle.data_rows.getColumn_data()[i]); //add all other data after
    }
    bundle.data_rows.setColumn_data(newData); //update the data bundle

    std::vector<std::string> newKeys;
    // Add the new record key to the existing keys
    newKeys.push_back(recordVector[0]); //add the new record key first

    for (int i = 0; i < bundle.row_keys.getIncident_numbers().size(); i++)
    {
        newKeys.push_back(bundle.row_keys.getIncident_numbers()[i]); //add all other keys after
    }
    bundle.row_keys.setIncident_numbers(newKeys); //update the data bundle

    return bundle;
};

/**
 * @brief Delete a record from the exisiting record.
 * NOTE: This does NOT remove the record from the file, just from the working memory. New file must still be written.
 *
 * @param bundle existing data
 */
Data_Bundle removeRecord(Data_Bundle bundle)
{
    string input;
    std::vector<vector<std::string>> temp;
    genericMessage("\nWhat is the incident number you wish to remove?: ");
    input = stringInput();
    int index = searchRecords(bundle, input);
    if (index > 0) // if the record is found (searchRecords returns -1 if not found)
    {
        // temp = bundle.data_rows.getColumn_data();
        // temp.erase(temp.begin() + index);
        // bundle.data_rows.setColumn_data(temp);
        bundle = removeRecord(bundle, index);
    }
    else
    {
        genericMessage("\nUnable to find the record.");
    }
    return bundle;
}

/**
 * @brief 
 * TODO: Consider changing this to recursively pull apart and add everything in the exisiting records to data EXCEPT the value chosen for deletion
 * 
 * @param bundle existing data
 * @param index index number of the record to be removed. 
 * @return Data_Bundle 
 */
Data_Bundle removeRecord(Data_Bundle bundle, int index)
{
    std::vector<vector<std::string>> temp;
    temp = bundle.data_rows.getColumn_data();
    temp.erase(temp.begin() + index);
    bundle.data_rows.setColumn_data(temp);

    return bundle;
}