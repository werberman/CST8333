#include "C:/SJunk/C++/CST8333/src/lib/csv.h"
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

using namespace std;

int main()
{
    int m;
    string fname = "C:/Sjunk/C++/pipeline-incidents-comprehensive-data.csv";

    Data_Bundle bundle;

    bundle = reader(fname);

    mainMenu();
    controller(menuSelectionInt(), bundle);

    // displayRecords(bundle);

    return 0;
}