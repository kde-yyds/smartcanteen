#ifndef CONFIG_H
#define CONFIG_H

#endif // CONFIG_H

#include <string>
#include <fstream>

#include "standardPath.h"

void writeConfig_String (std::string fileName, std::string Value)
{
    QString configDir;
    getConfigDir(configDir);
    chdir(configDir.toUtf8().data());
    remove (fileName.c_str());
    std::ofstream configFile (fileName);
    configFile << Value;
    configFile.close();
}

void writeConfig_Int (std::string fileName, int Value)
{
    QString configDir;
    getConfigDir(configDir);
    chdir(configDir.toUtf8().data());
    remove (fileName.c_str());
    std::ofstream configFile (fileName);
    configFile << Value;
    configFile.close();
}

void readConfig_String (std::string fileName, std::string &Value)
{
    QString configDir;
    getConfigDir(configDir);
    chdir(configDir.toUtf8().data());
    std::ifstream configFile (fileName);
    std::getline(configFile, Value);
    configFile.close();
}

void readConfig_Int (std::string fileName, int &Value)
{
    QString configDir;
    getConfigDir(configDir);
    chdir(configDir.toUtf8().data());
    std::ifstream configFile (fileName);
    configFile >> Value;
    configFile.close();
}



void writeData_String (std::string fileName, std::string Value)
{
    QString dataDir;
    getDataDir(dataDir);
    chdir(dataDir.toUtf8().data());
    remove (fileName.c_str());
    std::ofstream dataFile (fileName);
    dataFile << Value;
    dataFile.close();
}

void writeData_Int (std::string fileName, int Value)
{
    QString dataDir;
    getDataDir(dataDir);
    chdir(dataDir.toUtf8().data());
    remove (fileName.c_str());
    std::ofstream dataFile (fileName);
    dataFile << Value;
    dataFile.close();
}

void readData_String (std::string fileName, std::string &Value)
{
    QString dataDir;
    getDataDir(dataDir);
    chdir(dataDir.toUtf8().data());
    std::ifstream dataFile (fileName);
    std::getline(dataFile, Value);
    dataFile.close();
}

void readData_Int (std::string fileName, int &Value)
{
    QString dataDir;
    getDataDir(dataDir);
    chdir(dataDir.toUtf8().data());
    std::ifstream dataFile (fileName);
    dataFile >> Value;
    dataFile.close();
}
//TODO: store files in separate folders


//define some config varibles
int studentNumber = 40;
int currentNumber;
int itemNumber;
int currentItem;
int item[100]={1};

//we only want to read config when clicking "open settings" for the first time.
bool ifReadConfig = true;
//default is open settings, after clicking, turn to close settings ...
bool ifOpenSettings = true;
