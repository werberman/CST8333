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

struct Data_Headers
{
    vector<string> column_headers;
};

struct Data_Rows
{
    std::vector<vector<string>> column_data;
};

struct Row_Key
{
    std::vector<string> incident_numbers;
};

struct Data_Bundle 
{
    Data_Headers data_headers;
    Data_Rows data_rows;
    Row_Key row_keys;
};