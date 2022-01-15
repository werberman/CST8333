#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/**
 * @brief 
 * 
 * @return int 
 */
int menuSelectionInt()
{
    int i;
    std::cin >> i;
    return i;
}

/**
 * @brief 
 * 
 * @param i 
 */
void controller(int i)
{
    switch (i)
    {
    case 1:
    //reload the csv
    displayReloadCSV();
    break;

    case 2:
    //display the records
    break;

    case 3:
    //add a record
    break;

    case 4:
    //remove a record;
    break;

    case 5:
    //Save as a new csv file
    break;

    default:
    int fool;
    }
}
// TODO: Make an interface for this.