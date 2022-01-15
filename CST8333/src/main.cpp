#include "C:/SJunk/C++/CST8333/src/lib/csv.h"
#include "Data.cpp"
#include "reader.cpp"
#include "display.cpp"
#include "controller.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

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