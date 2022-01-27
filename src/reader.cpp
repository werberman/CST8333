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
#ifndef DISPLAY_CPP
#define DISPLAY_CPP
#include "display.cpp"
#endif
#ifndef DATA_CPP
#define DATA_CPP
#include "Data.cpp"
#endif

using namespace std;

string ReplaceAll(string str, const string& from, const string& to);

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
                row.push_back(ReplaceAll(string(word), string("*"), string(",")));
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

    //Make the Data_Bundle
    Data_Bundle bundle;
    bundle.data_headers = colHeader;
    bundle.data_rows = allData;
    bundle.row_keys = incidentNumbers;

    return bundle;
};

/**
 * @brief 
 * Replace all given substrings of a string with another substring
 * https://stackoverflow.com/questions/2896600/how-to-replace-all-occurrences-of-a-character-in-string
 * 
 * @param str string to be changed
 * @param from substring to be changed
 * @param to new substring
 * @return std::string 
 */
std::string ReplaceAll(std::string str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}
