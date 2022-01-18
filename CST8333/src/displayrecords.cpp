// Move this into the controller ??
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

/**
 * @brief CURRENTLY BROKEN...
 *
 * @param bundle
 */
void displayRecords(Data_Bundle bundle, int start, int length, int fields) // BROKEN - FIX THIS
{
    std::cout << "\nDEBUG: start: "
              << start
              << "\nDEBUG: length: "
              << length
              << "\nDEBUG: fields: "
              << fields;

    char chars[] = "\""; // Chars to be removed.


    for (int i = 0; i < fields /*|| i < bundle.data_headers.getColumn_headers().size()*/; i++) // make sure not to accidentally try and read records outside of range!!
    {
        cout << "*******************************\n"
             << bundle.data_headers.getColumn_headers()[i] << " : \n";
        for (int j = start; j < (start + length) /*|| j < (bundle.data_headers.getColumn_headers().size() - start)*/; j++)
        {
            cout << "Record No: " << (j + 1) << ": " << bundle.data_rows.getColumn_data()[j][i] << " -- " << j << "," << i << "\n";
        }
    }
    shamelessPlug();
};

void displayIncidentNos(Row_Key keys)
{
    for (int i = 0; i < keys.getIncident_numbers().size(); i++)
    {
        genericMessage(keys.getIncident_numbers()[i] + "\n");
    }
};

int found; // Declared here to ensure access to the variable outside the loop.
bool searchRecordsBool(Data_Bundle bundle, string incidentNo)
{
    bool foundFlag = false;
    bool noResultFlag = false;
    while (!foundFlag)
    {
        for (int i = 0; i < bundle.row_keys.getIncident_numbers().size(); i++)
        {
            if (bundle.row_keys.getIncident_numbers()[i] == incidentNo)
            {
                found = i;
                foundFlag = true;
            }
        } // When out of the above, if found flag is not true, entry was not in the dataset.
        if (!foundFlag)
        {
            noResultFlag = true;
        }
        cout << "\nDEBUG: foundFlag: "
             << foundFlag
             << "\nDEBUG: noResultFlag: "
             << noResultFlag
             << "\nDEBUG: found: "
             << found;
        break; // Get out of the while loop
    }
    if (foundFlag)
    {
        return true;
    }
    else
    {
        genericMessage("Unable to locate record. Please try again.");
        return false;
    }
};

int searchRecords() 
{
    return found; //this is the index value found in the function searchRecordsBool();
}

