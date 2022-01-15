//Move this into the controller ??
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

/**
 * @brief 
 * 
 * @param bundle 
 */
void displayRecords(Data_Bundle bundle)
{

    char chars[] = "\""; // Chars to be removed.

    displaySelectedNoRecords();

    int m;
    m = menuSelectionInt();
    cout << "\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "*******************************\n"
             << bundle.data_headers.getColumn_headers()[i] << " : \n";
        for (int j = 0; j < m; j++)
        {
            cout << "Record No: " << (j + 1) << ": " << bundle.data_rows.getColumn_data()[j][i] << "\n";
        }
    }

    cout << "\nBy: Kristopher Houston\nStudent No: 041015388\nCST8333\nWinter, 2022";
}