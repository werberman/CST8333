#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#ifndef DISPLAY_CPP
#define DISPLAY_CPP
#include "display.cpp"
#endif
#ifndef DATA_CPP
#define DATA_CPP
#include "Data.cpp"
#endif

using namespace std;

/**
 * @brief
 *
 * @param fname
 * @return Data_Bundle
 */
Data_Bundle reader(string fname)
{
    string message = "Loading CSV File...\n";
    genericMessage(message);
    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    vector<string> incidentNoVector;

    bool inquotes = false;
    string thing;

    fstream file(fname, ios::in);
    if (file.is_open())
    {
        while (getline(file, line)) // read in a line from the file
        {
            row.clear(); // clear the row vector so it's ready for new data

            // std::cout << line;

            // check each element in the line and see if it is a quotation mark
            for (int i = 0; i < line.size(); i++)
            {
                // Check if the character is a quote mark
                if (line[i] == '"')
                {
                    if (!inquotes)
                    {
                        inquotes = true;
                        thing = inquotes;
                        genericMessage(thing);
                    }
                    if (inquotes)
                    {
                        inquotes = false;
                        thing = inquotes;

                        genericMessage(thing);
                    }
                }
                // check if the character is a comma
                if (inquotes)
                {
                    genericMessage("TRIGGERED");
                    replace(line.begin(), line.end(), ',', '*');
                }
            }

            // cout << "\nDEBUG: Line: "
            //      << line;
            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout << "Could not open the file\n";

    // Place the header information in an object, then remove it from the vector
    Data_Headers colHeader;
    colHeader.setColumn_headers(content[0]);
    content.erase(content.begin());

    // Place the row data in an object.
    Data_Rows allData;
    allData.setColumn_data(content);

    Row_Key incidentNumbers;
    for (int i = 0; i < allData.getColumn_data().size(); i++)
    {
        incidentNoVector.push_back(allData.getColumn_data()[i][0]);
    }
    incidentNumbers.setIncident_numbers(incidentNoVector);

    Data_Bundle bundle;
    bundle.data_headers = colHeader;
    bundle.data_rows = allData;
    bundle.row_keys = incidentNumbers;

    return bundle;
}