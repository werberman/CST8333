/**
 * @file test.cpp
 * @author Kristopher Houston
 * @brief This file demonstrates the chosen unittest framework (doctest). This unit test framework is somewhat unique: it is well
 * suited to C++ because it can be loaded onto any C++ file (or link to any file using typical headers). It is then compiled as any
 * other C++ program: the output of the resulting binary are the test results!
 * @version 2.0
 * @date 2022-02-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "libraries/doctest.h"
#ifndef READER_CPP
#define READER_CPP
#include "reader.cpp"
#endif
#ifndef DATA_CPP
#define DATA_CPP
#include "Data.cpp"
#endif
#ifndef WRITECSV_CPP
#define WRITECSV_CPP
#include "writeCSV.cpp"
#endif
#ifndef THREAD
#define THREAD
#include <thread>
#endif

/**
 * @brief Extremely simple test case to show how the test works
 *
 * @param in integer in. This is multiplied by two and returned
 * @return int
 */
int tester(int in) { return (in * 2); }

/**
 * @brief All of these test cases should pass
 *
 */
TEST_CASE("testing the tester function - none should fail")
{
    CHECK(tester(0) == 0);
    CHECK(tester(2) == 4);
    CHECK(tester(3) == 6);
    CHECK(tester(10) == 20);
};


/**
 * @brief Get the Test Values - this is an example usage of reader();
 * 
 * @return Data_Bundle the bundled data 
 */
Data_Bundle getTestValues(string fname)
{
    Data_Bundle bundle;
    bundle = reader(bundle, fname);
    return bundle;
};


Data_Bundle bundle = getTestValues(".\\datafiles\\newcsv.csv"); //Stored data to be used in tests

Data_Bundle newFile = getTestValues(".\\datafiles\\THREADS.csv");

/**
 * @brief Write a new file using detached thread (syntax is exactly the same as in controller -
 * c_writeCSV but does away with user input to avoid having to write an intensly complex and 
 * unnecessairy stub function injection)
 * 
 */
void TestFileThreadingOutput()
{
    thread t_write(writeCSV, bundle, "THREADS.csv");
    t_write.detach();
};


/**
 * @brief Functional test case to see if the data loads as expected. This will pass.
 * 
 */
TEST_CASE("This is a functional test case to see if the data loads as expected")
{
    CHECK(bundle.data_headers.getColumn_headers()[0] == "Incident Number");
}

/**
 * @brief Functional test case to see if the data loads as expected. This will fail.
 * 
 */
TEST_CASE("Second functional test. This should FAIL")
{
    CHECK(bundle.data_headers.getColumn_headers()[0] == "Incident");
}

/**
 * @brief Functional test case to check that data being output by threaded file write is correct.
 * 
 */
TEST_CASE("Multithreading test. This should SUCCEED")
{
    CHECK(newFile.data_headers.getColumn_headers()[0] == bundle.data_headers.getColumn_headers()[0]);
}