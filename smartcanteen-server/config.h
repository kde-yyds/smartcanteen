#ifndef CONFIG_H
#define CONFIG_H

#endif // CONFIG_H

#include <string>
#include <fstream>

#include "path.h"

void writeData_String (std::string fileName, std::string Value, std::string subDirectory)
{
    std::string dataDir;
    getDataDir(dataDir);
    chdir(dataDir.c_str());
    chdir(subDirectory.c_str());
    remove (fileName.c_str());
    std::ofstream dataFile (fileName);
    dataFile << Value;
    dataFile.close();
}

void writeData_Int (std::string fileName, int Value, std::string subDirectory)
{
    std::string dataDir;
    getDataDir(dataDir);
    chdir(dataDir.c_str());
    chdir(subDirectory.c_str());
    remove (fileName.c_str());
    std::ofstream dataFile (fileName);
    dataFile << Value;
    dataFile.close();
}

void readData_String (std::string fileName, std::string &Value, std::string subDirectory)
{
    std::string dataDir;
    getDataDir(dataDir);
    chdir(dataDir.c_str());
    chdir(subDirectory.c_str());
    std::ifstream dataFile (fileName);
    std::getline(dataFile, Value);
    dataFile.close();
}

void readData_Int (std::string fileName, int &Value, std::string subDirectory)
{
    std::string dataDir;
    getDataDir(dataDir);
    chdir(dataDir.c_str());
    chdir(subDirectory.c_str());
    std::ifstream dataFile (fileName);
    dataFile >> Value;
    dataFile.close();
}

//define some config varibles
int studentNumber = 40;
int grade = 1;
int Class = 15;
int currentNumber;
int itemNumber;
int currentItem;
int item[100]={1};
