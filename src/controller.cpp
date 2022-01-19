#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#ifndef DISPLAYRECORDS_CPP
#define DISPLAYRECORDS_CPP
#include "displayrecords.cpp"
#endif
#ifndef ADDREMOVERECORD_CPP
#define ADDREMOVERECORD_CPP
#include "addRemoveRecord.cpp"
#endif
#ifndef DATA_CPP
#define DATA_CPP
#include "Data.cpp"
#endif
#ifndef CONTROLLER_CPP
#define CONTROLLER_CPP
#include "controller.cpp"
#endif
#ifndef WRITECSV_CPP
#define WRITECSV_CPP
#include "writeCSV.cpp"
#endif

string invalidMsg = "\nInvalid menu selection, please try again: ";

void displayRecController(Data_Bundle bundle); // forward declaration;
bool yesNo(char i);                            // forward declaration;

/**
 * @brief
 *
 * @param i
 * @param bundle
 */
void controller(int i, Data_Bundle bundle)
{
    string rldMsg = "\nThis will undo any changes you've made that haven't been saved and reload the orginal file. Are you sure? (y/n): ";
    string addMsg = "\nAdding a record: \nPlease input each field one at a time when prompted:\n";
    string dltMsg = "\nDo you know the incident number of the record you wish to delete? (y/n): ";
    string currentINo = "\nThe following are the current incident numbers: \n";
    string reviewMsg = "\nYou can review the current incident numbers from the main menu.";

    string newCSV;
    string newFileName;

    bool loopCtrl = true;

    ofstream newFile;

    // while (loopCtrl) //doesn't work like I'd have expected...
    // {
    switch (i)
    {
    case 1:
        // reload the csv
        char i;
        genericMessage(rldMsg);
        i = menuSelectionChar();
        // reloadCSV(i);
        break;

    case 2:
        // displayRecords(bundle);
        displayRecController(bundle);
        break;

    case 3:
        // add a record

        genericMessage(addMsg);
        addRecord(bundle);
        break;

    case 4:
        // remove a record;
        genericMessage(dltMsg);
        if (yesNo(menuSelectionChar()))
        {
            removeRecord(bundle);
        }
        else
        {
            genericMessage(reviewMsg);
        }
        break;

    case 5:
        // Save as a new csv file
        cout << "DEBUG - Case 5 triggered - about to go to writeCSV";
        genericMessage("\nName your new file(do not include \".csv\"): ");
        newFileName = stringInput();
        newCSV = writeCSV(bundle);
        cout << "DEBUG - Cleared the writeCSV function";
        newFileName = newFileName + ".csv";       // TODO: Check syntax of this
        newFile.open("C:/Sjunk/C++/newcsv1.csv"); // TODO: Change this once testing is done to use user filename
        newFile << newCSV;                        // write the string to the new file
        newFile.close();                          // close the file
        break;

    case 6:
        // display current incident numbers
        genericMessage(currentINo);
        displayIncidentNos(bundle.row_keys);
        break;

    case 9:
        // DEBUG
        displayRecords(bundle, 0, 5, 3);
        break;

    case 0:
        // Exit program
        genericMessage("\nGoodbye!");
        shamelessPlug();
        loopCtrl = false;
        break;

    default:
        genericMessage(invalidMsg);
    }
};

/**
 * @brief display record controller logic is here
 *
 * @param bundle current data
 */
void displayRecController(Data_Bundle bundle)
{
    displayRecMenu();
    int i = menuSelectionInt();
    int start;
    int num;
    int col;
    string incidentNo;
    int index;

    switch (i)
    {
    case 1:
        //"1) Display selected number of records starting from any point in the data\n"
        genericMessage("Where would you like to start displaying records? Input desired record number (0 being the first record): ");
        start = menuSelectionInt();
        genericMessage("\nHow many records would you like to display?: ");
        num = menuSelectionInt();
        genericMessage("\nHow many data fields would you like to display?: ");
        col = menuSelectionInt();
        std::cout << "Start: "
                  << start
                  << "\nnum: "
                  << num
                  << "\ncol: "
                  << col;

        std::cout << bundle.data_headers.getColumn_headers()[start]
                  << "\n"
                  << bundle.data_rows.getColumn_data()[num][start];

        displayRecords(bundle, start, num, col);
        break;

    case 2:
        //"2) Search for a specific record by Incident Number";
        genericMessage("\nWhat is the specific incident number you are looking for?: ");
        incidentNo = stringInput();
        index = searchRecords(bundle, incidentNo);
        if (index > 0) // searchRecords() returns -1 if the record is not found
        {
            displayRecords(bundle, index, 1, 101 /*All the fields*/);
        }
        else
        {
            genericMessage("Record could not be found.");
        }
        break;

    default:
        genericMessage(invalidMsg);
        break;
    }
};

/**
 * @brief Check if a character response is a true or false:
 *
 * @param i character to be checked
 * @return true if y/Y
 * @return false if f/F
 */
bool yesNo(char i)
{
    bool yesNo;
    if (i == 'y' || i == 'Y')
    {
        yesNo = true;
    }
    else
    {
        yesNo = false;
    }
    return yesNo;
};

// void reloadCSV(char i)
// {
//     if (i == 'y' || i == 'Y')
//     {
//         reader(fname);
//     }
//     else if (i == 'n' || i == 'N')
//     {
//     }
// }
// TODO: Make an interface for this.