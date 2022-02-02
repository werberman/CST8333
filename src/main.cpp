// #include "C:/SJunk/C++/CST8333/src/lib/csv.h"

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
#include <filesystem>

using namespace std;

int main()
{
    // File location (relative) of the csv.
    string fname = ".\\datafiles\\pipeline-incidents-comprehensive-data.csv";

    Data_Bundle bundle;

//Try to open the file, catch if it fails.
    try
    {
        bundle = reader(bundle, fname);
    }
    catch (Read_Exception &e1)
    {
        genericMessage("Unable to open the CSV file!");
        return 0; // currently set to simply exit if this happens.
    }

    controller(bundle, fname); //Primary logic is handled here.

    // displayRecords(bundle);

    return 0;
}