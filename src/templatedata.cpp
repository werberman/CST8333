#ifndef STRING
#define STRING
#include <string>
#endif
#ifndef VECTOR
#define VECTOR
#include <vector>
#endif

using namespace std;

static const vector<string> RECORD_TEMPLATE =
    {
        "INC2022-TEST", //Incident Number
        "N/A", //Incident Type
        "01/01/2022", //Reported Date
        "N/A",
        "N/A",
        "N/A",
        "Open",
        "0.0000", //Latitude
        "0.0000", //Longitude
        "N/A",
        "N/A",
        "N/A",
        "No",
        "2022",
        "2022/01/01 00:00:00 AM Eastern", //Occurence Date and Time
        "2022/01/01",
        "N/A",
        "N/A",
        "N/A",
        "N/A", //Why it happened category
        "",
        "",
        "N/A",
        "N/A",
        "N/A",
        "No", //Pipeline or facility equipment involved
        "No",
        "N/A",
        "N/A",
        "0", //Released volume (m3)
        "No",
        "No",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "0", //Number of people evacuated
        "OPR",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Canada",//Country
        "No",
        "No",
        "No",
        "No",
        "Unknown",//Land use
        "Unknown",
        "N/A",
        "Level I",//Emergency level
        "N/A",
        "No",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "0",//Licensed maximum operating pressure (kPa)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",//Year when the coating was applied
        "No",
        "",
        "",
        "No",
        "",
        "",
        "No",//Most recent inspection part of the routine inspection program
        "No",
        "",
        "",
        "No"
    };