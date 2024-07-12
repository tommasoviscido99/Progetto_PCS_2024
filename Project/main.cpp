#include "fracture.hpp"
#include <iostream>
#include <vector>
#include "fracture_tests.hpp"
#include <gtest/gtest.h>

using namespace std;

int main(int argc, char **argv) {

    string inputFilename = "/Users/tommasoviscido/Downloads/Progetto_PCS_2024/Project/DFN/FR3_data.txt";
    vector<Fracture> fractures = readFractures(inputFilename);

    vector<Trace> traces = computeTraces(fractures);
    string outputFilename = "traces.txt";
    writeTraces(traces, outputFilename);

    string outputClassifiedFilename = "output.txt";
    classifyAndWriteTracesByFracture(fractures, traces, outputClassifiedFilename);

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
