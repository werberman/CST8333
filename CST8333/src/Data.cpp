#include <string>
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

// class Data
// {
// public:
//     vector<string> stringData;
//     Data(vector<string> row)
//     {
//         stringData = row;
//     }
// };