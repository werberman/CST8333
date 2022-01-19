#ifndef ALGORITHM
#define ALGORITHM
#include <algorithm>
#endif
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

using namespace std;

/**
 * @brief
 *
 * @param fname
 * @return Data_Bundle
 */
Data_Bundle reader(string fname)
{
    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    vector<string> incidentNoVector;

    bool inquotes = false;

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
                if (line[i] == '\"')
                {
                    if (!inquotes)
                    {
                        inquotes = true;
                    }
                    else if (inquotes)
                    {
                        inquotes = false;
                    }
                };
                // check if the character is a comma and switch it to a star
                if (inquotes && line[i] == ',')
                {
                    line[i] = '*';
                }
            }

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
                content.push_back(row);
        }
        // Change the stars back to commas
        // for (int i = 0; i < content.size(); i++)
        // {
        //     cout << content[0].size();
        //     cout << content.size();
        //     cout << "\nTEMP";
        //     for (int j = 0; j < content[0].size(); i++)
        //     {
        //         cout << "BLAH";
        //         // content[j][i].replace(content[j][i].begin(), content[j][i].end(), '*', ',');
        //     }
        // };
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

    //Make the Data_Bundle
    Data_Bundle bundle;
    bundle.data_headers = colHeader;
    bundle.data_rows = allData;
    bundle.row_keys = incidentNumbers;

    return bundle;
}