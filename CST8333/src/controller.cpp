#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "displayrecords.cpp"
#include "addRemoveRecord.cpp"

/**
 * @brief
 *
 * @param i
 */
void controller(int i, Data_Bundle bundle)
{
    string rldMsg = "\nThis will undo any changes you've made that haven't been saved and reload the orginal file. Are you sure? (y/n): ";
    string addMsg = "\nAdding a record: \nPlease input each field one at a time when prompted:\n";
    string invalidMsg = "\nInvalid menu selection, please try again: ";
    string dltMsg = "\nDo you know the incident number of the record you wish to delete? (y/n): ";
    string currentINo = "\nThe following are the current incident numbers: \n";
    string reviewMsg = "\nYou can review the current incident numbers from the main menu.";

    bool loopCtrl = true;

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
        displayRecords(bundle);
        break;

    case 3:
        // add a record

        genericMessage(addMsg);
        addRecord(bundle);
        break;

    case 4:
        // remove a record;
        // genericMessage(dltMsg);
        // if (yesNo(menuSelectionChar()))
        // {
        //     removeRecord(bundle);
        // }
        // else
        // {
        //     genericMessage(reviewMsg);
        // }

        break;

    case 5:
        // Save as a new csv file
        break;

    case 6:
        // display current incident numbers
        genericMessage(currentINo);
        break;

    case 0:
        // Exit program
        loopCtrl = false;
        break;

    default:
        genericMessage(invalidMsg);
    }
}
// }

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
}
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