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

class Data_Rows
{
private:
    std::vector<vector<string>> column_data;

public:
    void setColumn_data(std::vector<vector<string>> col)
    {
        column_data = col;
    }

    std::vector<vector<string>> getColumn_data()
    {
        return column_data;
    }
};

class Data_Headers
{
private:
    std::vector<string> column_headers;

public:
    void setColumn_headers(std::vector<string> head)
    {
        column_headers = head;
    }

    std::vector<string> getColumn_headers()
    {
        return column_headers;
    }
};

class Row_Key
{
private:
    std::vector<string> incident_numbers;

public:
    void setIncident_numbers(std::vector<string> ino)
    {
        incident_numbers = ino;
    }

    std::vector<string> getIncident_numbers()
    {
        return incident_numbers;
    }
};

// class Data_Bundle
// {
// private:
//     Data_Headers data_headers;
//     Data_Rows data_rows;
//     Row_Key row_keys;

// public:
//     void setColumn_data(Data_Rows col)
//     {
//         data_rows.setColumn_data(col.getColumn_data);
//     }

//     void setColumn_headers(Data_Headers head)
//     {
//         data_headers.setColumn_headers(head.getColumn_headers);
//     }

//     void setIncident_numbers(Row_Key ino)
//     {
//         row_keys.setIncident_numbers(ino.getIncident_numbers);
//     }

//     Data_Rows getRecords()
//     {
//         return data_rows;
//     }

//     Row_Key getINo()
//     {
//         return row_keys;
//     }

//     Data_Headers getHeaders()
//     {
//         return data_headers;
//     }
// };

// /**
//  * @brief
//  *
//  */
// struct Data_Headers
// {
//     vector<string> column_headers;
// };

// /**
//  * @brief
//  *
//  */
// struct Data_Rows
// {
//     std::vector<vector<string>> column_data;
// };

// /**
//  * @brief
//  *
//  */
// struct Row_Key
// {
//     std::vector<string> incident_numbers;
// };

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