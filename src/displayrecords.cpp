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
#ifndef READER_CPP
#define READER_CPP
#include "reader.cpp"
#endif
#ifndef DISPLAY_CPP
#define DISPLAY_CPP
#include "display.cpp"
#endif


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

    for (int i = 0; i < fields /*|| i < bundle.data_headers.getColumn_headers().size()*/; i++) // make sure not to accidentally try and read records outside of range!!
    {
        cout << "*******************************\n"
             << bundle.data_headers.getColumn_headers()[i] << " : \n";
        for (int j = start; j < (start + length) || j < (bundle.data_headers.getColumn_headers().size() - start); j++)
        {
            cout << "Record No: " << (j + 1) << ": " << bundle.data_rows.getColumn_data()[j][i] /*<< " -- " << j << "," << i*/ << endl; // Clear the output buffer after each line
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
        genericMessage(keys.getIncident_numbers()[i]);
    }
};

int found; // Declared here to ensure access to the variable outside the loop.
/**
 * @brief Check if a given incident number value is found in a given data bundle. The index number of the found record is
 * saved in an int outside the function so that it can be called later.
 *
 * @param bundle data bundle
 * @param incidentNo desired incident number
 * @return -1 if record cannot be found
 * @return index number if found
 */
int searchRecords(Data_Bundle bundle, string incidentNo)
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
        break; // Get out of the while loop
    }
    if (foundFlag)
    {
        return found;
    }
    else
    {
        genericMessage("Unable to locate record. Please try again."); //consider moving this out of here and into functions that call it
        return -1;
    }
};