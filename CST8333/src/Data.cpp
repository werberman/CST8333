#include <string>
using namespace std;

/**
 * @brief 
 * 
 */
struct Data_Headers
{
    vector<string> column_headers;
};

/**
 * @brief 
 * 
 */
struct Data_Rows
{
    std::vector<vector<string>> column_data;
};

/**
 * @brief 
 * 
 */
struct Row_Key
{
    std::vector<string> incident_numbers;
};

/**
 * @brief 
 * 
 */
struct Data_Bundle 
{
    Data_Headers data_headers;
    Data_Rows data_rows;
    Row_Key row_keys;
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