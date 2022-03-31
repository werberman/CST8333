/**
 * @file main.cpp
 * @author Kristopher Houston - 041015388
 * @brief Primary entry point of the program
 * @version 3.0
 * @date 2022-02-18
 *
 * NOTE: As we discuessed privately, while this project is generic in that it will work with virtually any .csv,
 * the search function is very specifically tied to the Incident Numbers column and I have documented the entire
 * project both in docs and in the incremental updates that have been made over the course of the project (GitHub
 * access is available upon request). If you have any concerns or comments, please do not hesitate to contact me.
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef DATA_CPP
#define DATA_CPP
#include "Data.cpp"
#endif
#ifndef READER_CPP
#define READER_CPP
#include "reader.cpp"
#endif
#ifndef DISPLAY_CPP
#define DISPLAY_CPP
#include "display.cpp"
#endif
#ifndef CONTROLLER_CPP
#define CONTROLLER_CPP
#include "controller.cpp"
#endif
#ifndef EXCEPTION
#define EXCEPTION
#include <exception>
#endif
#ifndef FUTURE
#define FUTURE
#include <future>
#endif

using namespace std;

/**
 * @brief Start the program.
 * This also does the inital loading of the data from the .csv file. Loading is done on a seperate thread with the value
 * being placed in a future so that if for some reason it is slow to load, the partly loaded values can be used in the intrim. 
 *
 * @return int
 */
int main()
{
    // File location (relative) of the csv.
    // string fname = ".\\datafiles\\pipeline-incidents-comprehensive-data.csv";
    string fname = ".\\datafiles\\newcsv.csv"; //The original file is (I suspect) too large for the output buffer. I will likely fix
                                               //that going forward, but for now, this truncated test file shows full functionality. 
                                               //This data file contains all columns, but only 100 records (plus the headers).
                                               //Original file does work, but slows down to a crawl.

    Data_Bundle bundle;

    // Try to open the file, catch if it fails.
    try
    {
        std::future<Data_Bundle> future = std::async(reader, bundle, fname);
        bundle = future.get();
    }
    catch (Read_Exception &e1)
    {
        genericMessage("Unable to open the CSV file!");
        return 0; // currently set to simply exit if this happens.
    }

    controller(bundle, fname); // Primary logic is handled here.

    // displayRecords(bundle);

    return 0;
}