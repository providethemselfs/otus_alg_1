#ifndef _TESTINGBASE_
#define _TESTINGBASE_

#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

class TestingBase
{
public:
    void run(char * directoryPath);

protected:
    std::string makeFullPath(std::string fileName);

private:
    virtual void runTest(std::string fileName) = 0;

    fs::path dirPath;
};

#endif