#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

void addRecord(Data_Bundle bundle)
{
    Data_Rows newRecord;
    std::vector<std::string> recordVector;

    //Prompt for each field by iterating through the column headers.
    for (int i = 0; i < bundle.data_headers.column_headers.size(); i++)
    {
        std::string currentField = bundle.data_headers.column_headers[i] + ": ";
        genericMessage(currentField);
        //modify each input to match csv formatting and place in the vector
        recordVector.push_back("\"" + stringInput() + "\",");
    }
    //add a carrage return to the end of the record
    recordVector.push_back("\n");
};

void removeRecord(Data_Bundle bundle)
{
    std::string deleteRecord;

}