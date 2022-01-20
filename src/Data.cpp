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
 * @brief Individual rows of data broken into columns (stored as a vector). Column headers should NOT be included here.
 * 
 */
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

/**
 * @brief First line of a csv (presumably the data header) is stored here for quick access as a vector.
 * 
 */
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

/**
 * @brief A vector of the incident numbers (a unique value). This allows for quick checks when a record is being searched. 
 * 
 */
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
 * @brief Full bundle of all the data types (Data_Headers, Data_Rows, and Row_Key). 
 *
 */
struct Data_Bundle
{
    Data_Headers data_headers;
    Data_Rows data_rows;
    Row_Key row_keys;
};

struct Read_Exception : public exception 
{
    const char * what () const throw () 
    {
        return "Reader Exception";
    }
};