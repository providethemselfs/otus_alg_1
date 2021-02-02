#include <string>
#include <fstream>
#include <cassert>
#include "testingbase.h"


class TestingString : public TestingBase
{
private:
    virtual void runTest(std::string fileName) override;
};

void TestingString::runTest(std::string fileName)
{
    std::cout  << "running " << fileName << std::endl;

    std::string fileNameIn = makeFullPath(fileName + ".in");
    

    std::ifstream fileIn(fileNameIn);
    if(!fileIn)
    {
        std::cout << "wrong filename for input: " << fileNameIn << std::endl;
        return;
    }

    std::string stringInFile;
    fileIn >> stringInFile;
    //std::cout << stringInFile.size() << std::endl;

    std::string fileNameOut = makeFullPath(fileName + ".out");
    std::ifstream fileOut(fileNameOut);
    if(!fileOut)
    {
        std::cout << "wrong filename for result: " << fileNameOut << std::endl;
        return;
    }

    int mustBeSize;
    fileOut >> mustBeSize;

    if(mustBeSize != stringInFile.size())
    {
        std::cout << fileName << " failed!" << std::endl;
    }

}


int main(int argc, char** argv)
{
    std::cout << "otus alg 0.String" << std::endl;
    
    

    if(argc == 1)
    {
        std::cout << "use: otus1 <dirname>" << std::endl;
        return 0;
    }
    else
    {
        TestingString testString;
        testString.run(argv[1]);
        std::cout << "all tests completed!";
        //std::cout << pathToDir.c_str() << std::endl;
        //argv[1]

    }

    

    return 0;
}