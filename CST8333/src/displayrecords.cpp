// Move this into the controller ??
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

/**
 * @brief Display records. Fields displayed are controlled by the start and length fields, and the 'fields' field controlls the columns 
 * that are displayed. 
 * 
 * @param bundle data bundle to be used in the display.
 * @param start where in the data to start (index number)
 * @param length number of records to display
 * @param fields number of columns to display for each record.
 */
void displayRecords(Data_Bundle bundle, int start, int length, int fields)
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

/**
 * @brief Displays all the existing incident numbers
 * 
 * @param keys Row_Keys data that should be displayed.
 */
void displayIncidentNos(Row_Key keys)
{
    for (int i = 0; i < keys.getIncident_numbers().size(); i++)
    {
        genericMessage(keys.getIncident_numbers()[i] + "\n");
    }
};

int found; // Declared here to ensure access to the variable outside the loop.
/**
 * @brief THIS MUST BE CALLED BEFORE searchRecords() - Check if a gien incident number value is found in a given data bundle. The index number of the found record is 
 * saved in an int outside the function so that it can be called later. 
 * 
 * @param bundle data bundle
 * @param incidentNo desired incident number
 * @return true if found
 * @return false if not found
 */
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

/**
 * @brief searchRecordsBool() MUST BE CALLED IMMEDIATELY BEFORE THIS. Returns the index value of the found record.
 * 
 * @return int index value of the found record from searchRecordsBool()
 */
int searchRecords() 
{
    return found; //this is the index value found in the function searchRecordsBool();
}

