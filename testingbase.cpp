#include "testingbase.h"

void TestingBase::run(char * directoryPath)
{
    this->dirPath = directoryPath; 
    for(auto&p : fs::directory_iterator(directoryPath))
    {
        std::string filePathExtention = p.path().filename().extension().string();

        if(filePathExtention == ".in")
        {
            runTest(p.path().stem());
        }
    }
}

std::string TestingBase::makeFullPath(std::string fileName)
{
    fs::path fileNamePath = fileName;

    return this->dirPath / fileNamePath;
}