/**
 * @file controller.cpp
 * @author Kristopher Houston - 041015388
 * @brief All control logic is contained here. As such, all classes contained herein are effectively focused on
 * translating user input into the appropriate function calls
 * @version 0.1
 * @date 2022-02-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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
#ifndef THREAD
#define THREAD
#include <thread>
#endif

bool c_writeCSV(Data_Bundle bundle);

string invalidMsg = "\nInvalid menu selection, please try again: ";

void displayRecController(Data_Bundle bundle); // forward declaration;
bool yesNo(char i);                            // forward declaration;

/**
 * @brief Primary display controller. Handles most interactions with the user
 * 
 * @param bundle bundle of data from the csv
 * @param fname directory to the csv that is loaded into bundle (used to reload upon user request)
 */
void controller(Data_Bundle bundle, string fname)
{
    string rldMsg = "\nThis will undo any changes you've made that haven't been saved and reload the orginal file. Are you sure? (y/n): ";
    string dltMsg = "\nDo you know the incident number of the record you wish to delete? (y/n): ";
    string reviewMsg = "\nYou can review the current incident numbers from the main menu.";

    string newFileName;
    string incidentNo;

    bool loopCtrl = true;
    bool taskSuccess;

    int index;

    mainMenu();
    int menuSelect = menuSelectionInt(); // Get menu selection

    while (true)
    {
        switch (menuSelect)
        {
        case 1:
            // reload the csv
            char i;
            genericMessage(rldMsg);
            i = menuSelectionChar();
            if (yesNo(i))
            {
                try
                {
                    bundle = reader(bundle, fname); // See if this causes a memory leak
                }
                catch (Read_Exception &r1)
                {
                    genericMessage("Cannot reload the CSV... You may still be able to save your work. Do you want to continue (y/n)?: ");
                    i = menuSelectionChar();
                    if (yesNo(i))
                    {
                        if (!c_writeCSV(bundle))
                        {
                            genericMessage("Do you wish to continue (y/n)?: ");
                            if (!yesNo(menuSelectionChar()))
                            {
                                loopCtrl = false;
                            }
                        }
                    }
                }
            }
            // reloadCSV(i);
            break;

        case 2:
            // displayRecords(bundle);
            displayRecController(bundle);
            break;

        case 3:
            // add a record

            genericMessage("Adding a record: \nPlease input each field one at a time when prompted: ");
            genericMessage("If at any time you wish to fill the rest of the values with the default template values, enter DEFAULT for any of the fields: ");
            bundle = addRecord(bundle);
            break;

        case 4:
            // remove a record;
            genericMessage(dltMsg);
            if (yesNo(menuSelectionChar()))
            {
                bundle = removeRecord(bundle);
            }
            else
            {
                genericMessage(reviewMsg);
            }
            break;

        case 5:
            // Save as a new csv file
            taskSuccess = c_writeCSV(bundle);
            /*
             *TODO: add handler for if the file cannot be written.
             */
            /*
            *TODO: Consider making this occur on its owne thread
            */
            break;

        case 6:
            // display current incident numbers
            genericMessage("The following are the current incident numbers: ");
            displayIncidentNos(bundle.row_keys);
            break;

        case 7:
            // Edit an existing record
            genericMessage("What is the incident number of the record you wish to edit?: ");
            incidentNo = stringInput();
            index = searchRecords(bundle, incidentNo);
            if (index > 0) // searchRecords() returns -1 if the record is not found
            {
                editRecord(bundle, index);
            }
            else
            {
                genericMessage("Record could not be found.");
            }
            break;

        case 9:
            // DEBUG
            displayRecords(bundle, 0, 3, 50);
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

        if (loopCtrl)
        {
            mainMenu();
            menuSelect = menuSelectionInt();
        }
        else
        {
            break; // Break the menu loop
        }
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
    int menuSelect = menuSelectionInt();
    int start;
    int num;
    int col;
    string incidentNo;
    int index;
    bool loopCtrl = true;

    while (true)
    {
        switch (menuSelect)
        {
        case 1:
            //"1) Display selected number of records starting from any point in the data\n"
            genericMessage("Where would you like to start displaying records? Input desired record number (0 being the first record): ");
            start = menuSelectionInt();
            genericMessage("\nHow many records would you like to display?: ");
            num = menuSelectionInt();
            genericMessage("\nHow many data fields would you like to display?: ");
            col = menuSelectionInt();

            displayRecords(bundle, start, num, col);
            break;

        case 2:
            //"2) Search for a specific record by Incident Number";
            genericMessage("\nWhat is the specific incident number you are looking for?: ");
            incidentNo = stringInput();
            index = searchRecords(bundle, incidentNo);
            if (index > 0) // searchRecords() returns -1 if the record is not found
            {
                displayRecords(bundle, index, 1, bundle.data_headers.getColumn_headers().size() /*All the fields*/);
            }
            else
            {
                genericMessage("Record could not be found.");
            }
            break;

        case 3:
            // Show all records
            genericMessage("Are you sure? This can take quite a while and may not display properly. (y/n): ");
            if (yesNo(menuSelectionChar()))
            {
                cout << bundle.data_rows.getColumn_data().size()
                     << ", "
                     << bundle.data_rows.getColumn_data()[0].size();
                displayRecords(bundle, 0, bundle.data_rows.getColumn_data().size(), bundle.data_rows.getColumn_data()[0].size());
            }
            else
            {
                break;
            }
            break;

        case 9:
            // Go back to main menu
            loopCtrl = false;
            break;

        default:
            genericMessage(invalidMsg);
            break;
        }

        if (loopCtrl)
        {
            displayRecMenu();
            menuSelect = menuSelectionInt();
        }
        else
        {
            // TODO: Going back sometimes causes an infinite loop
            break; // break the menu loop
        }
    }
};

/**
 * @brief Check if a character response is a true or false:
 *
 * @param i Char - character to be checked
 * @return true if y/Y
 * @return false if f/F
 */
bool yesNo(char i)
{
    bool yesNo;
    while (true)
    {
        if (i == 'y' || i == 'Y')
        {
            yesNo = true;
            break;
        }
        else if (i == 'n' || i == 'N')
        {
            yesNo = false;
            break;
        }
        else
        {
            genericMessage("Invalid selection. Please try again: ");
            i = menuSelectionChar();
        }
    }
    return yesNo;
};


/**
 * @brief controller for input/output related to writing a new csv file from the passed in bundle. 
 * This is done on a seperate, detached thread and prints a notification to the user when the task has been
 * completed successfully. 
 * 
 * @param bundle bundled csv data to be written
 * @param newFileName name of the new file 
 * @return true 
 * @return false 
 */
bool c_writeCSV(Data_Bundle bundle)
{
    genericMessage("\nName your new file(do not include \".csv\"): ");
    string newFileName = ".\\datafiles\\" + stringInput();
    newFileName = newFileName + ".csv";
    genericMessage("File writing is done in the background and may take a few moments. You can continue to use the program, but don't exit until the saving is complete.");
    genericMEssage("This is done using multithrading. A message will appear in the console when the file is finished writing.");
    try
    {
        thread t_write(writeCSV, bundle, newFileName);
        t_write.detach(); //detach the thread and have it run independantly
    }
    catch (Write_Exception &w1)
    {
        genericMessage("Unable to create or open the requested file. Check folder permissions and try again.");
        return false;
    }
    return true;
};