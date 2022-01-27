// #include "C:/SJunk/C++/CST8333/src/lib/csv.h"

#ifndef DATA_CPP
#define DATA_CPP
#include "Data.cpp"
#endif
#include "reader.cpp"
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

using namespace std;

int main()
{
    // string fname = "C:/SJunk/C++/newcsv.csv";
    // string fname = "C:/Users/werbe/Documents/Programming Files/C++/CST8333/newcsv.csv";
    string fname = "c:/SJunk/C++/pipeline-incidents-comprehensive-data.csv";

    Data_Bundle bundle;

    try{
    bundle = reader(bundle, fname);
    }
    catch (Read_Exception &e1)
    {
        genericMessage("Unable to open the CSV file!");
        return 0; //currently set to simply exit if this happens.
    }

    controller(bundle, fname);

    // displayRecords(bundle);

    return 0;
}