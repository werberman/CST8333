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
#ifndef TEMPLATEDATA_CPP
#define TEMPLATEDATA_CPP
#include "templatedata.cpp"
#endif

Data_Bundle removeRecord(Data_Bundle bundle, int index);
vector<string> defaultRecordFiller(vector<std::string>, int index, int size);

/**
 * @brief add a record to the existing records
 *
 * @param bundle current data
 */
Data_Bundle addRecord(Data_Bundle bundle)
{
    std::vector<std::string> recordVector;
    std::string recordHolder = "";

    // Prompt for each field by iterating through the column headers.
    for (int i = 0; i < bundle.data_headers.getColumn_headers().size(); i++)
    {
        std::string currentField = bundle.data_headers.getColumn_headers()[i] + ": ";
        genericMessage(currentField);
        // modify each input to match csv formatting and place in the vector
        recordHolder = stringInput();
        if (recordHolder == "DEFAULT")
        {
            genericMessage("Filling the rest of the record with the default values");
            recordVector = defaultRecordFiller(recordVector, i, bundle.data_headers.getColumn_headers().size()); // send the record to a template generator function and save it to recordVector.
            break;
        }
        recordVector.push_back(recordHolder);
        recordHolder.clear();
    }

    std::vector<vector<std::string>> newData;
    // Add the new record into the existing data
    newData.push_back(recordVector); // put the new record in first.
    for (int i = 0; i < bundle.data_rows.getColumn_data().size(); i++)
    {
        newData.push_back(bundle.data_rows.getColumn_data()[i]); // add all other data after
    }
    bundle.data_rows.setColumn_data(newData); // update the data bundle

    std::vector<std::string> newKeys;
    // Add the new record key to the existing keys
    newKeys.push_back(recordVector[0]); // add the new record key first

    for (int i = 0; i < bundle.row_keys.getIncident_numbers().size(); i++)
    {
        newKeys.push_back(bundle.row_keys.getIncident_numbers()[i]); // add all other keys after
    }
    bundle.row_keys.setIncident_numbers(newKeys); // update the data bundle

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
    genericMessage("Current index number: ");
    cout << index;
    std::vector<vector<std::string>> temp;
    std::vector<string> tempKey;

    // Remove the row from the data records
    temp = bundle.data_rows.getColumn_data(); // move data into temp
    temp.erase(temp.begin() + index);         // remove the record
    bundle.data_rows.setColumn_data(temp);    // update the data bundle

    // Remove the row key from the index
    tempKey = bundle.row_keys.getIncident_numbers(); // move data into tempKeys
    tempKey.erase(tempKey.begin() + index);          // remove the record.
    bundle.row_keys.setIncident_numbers(tempKey);    // update the data bundle.

    return bundle;
}

/**
 * @brief Fill the remaining fields with the values found in the default template.
 *
 * @param recordVector new record currently being made by user
 * @param index current column to be input
 * @param size total number of columns in the record.
 * @return vector<string> of the finished new record.
 */
vector<string> defaultRecordFiller(vector<string> recordVector, int index, int size)
{
    for (int i = index; i < size; i++)
    {
        recordVector.push_back(RECORD_TEMPLATE[i]); // see if I can find a more effecient way to do this.
        cout << ".";                                // Theoretically a loading bar...
    }
    return recordVector;
}

/**
 * @brief TODO: Not working because the console does not recognize a blank input as input at all.
 * 
 * @param bundle: all of the bundled data
 * @param index: index number of the record to be modifieds
 */
void editRecord(Data_Bundle bundle, int index)
{
    vector<vector<string>> temp;
    vector<string> newRecord;
    string input = "";
    genericMessage("Enter new value for each column as it appears on the screen. If no change is required, press enter without entering anything.");

    for (int i = 0; i < bundle.data_headers.getColumn_headers().size(); i++)
    {
        genericMessage("Current Value: " + bundle.data_headers.getColumn_headers()[i] + "\n");
        input = stringInput();
        if (input != "")
        {
            newRecord.push_back(input); // place it in the new record vector
        }
        else
        {
            newRecord.push_back(bundle.data_rows.getColumn_data()[index][i]); // put the value currently stored in that column into the new record.
        }
        input.clear(); // clear the string
    }
    temp = bundle.data_rows.getColumn_data(); //move the datarecords into a temporary vector (temp)
    temp[index] = newRecord; //modify the selected record
    bundle.data_rows.setColumn_data(temp); //replace the Data_Bundle data
}