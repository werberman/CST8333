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


/*************************************** Errors ******************************/
struct Read_Exception : public exception 
{
    const char * what () const throw () 
    {
        return "Reader Exception";
    }
};

struct Write_Exception : public exception 
{
    const char * what () const throw () 
    {
        return "File Write Exception";
    }
};

struct End_of_Records_Exception : public exception
{
    const char * what () const throw ()
    {
        return "End of Records Reached";
    }
};

// struct Input_Error : public exception 
// {
//     const char * what () const throw () 
//     {
//         return "Invalid Input Exception";
//     }
// };