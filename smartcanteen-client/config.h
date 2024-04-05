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



void writeData_String (std::string fileName, std::string Value, std::string subDirectory)
{
    QString dataDir;
    getDataDir(dataDir);
    chdir(dataDir.toUtf8().data());
    if (!boost::filesystem::is_directory(subDirectory))
    {
        boost::filesystem::create_directories(subDirectory);
    }
    chdir(subDirectory.c_str());
    remove (fileName.c_str());
    std::ofstream dataFile (fileName);
    dataFile << Value;
    dataFile.close();
}

void writeData_Int (std::string fileName, int Value, std::string subDirectory)
{
    QString dataDir;
    getDataDir(dataDir);
    chdir(dataDir.toUtf8().data());
    if (!boost::filesystem::is_directory(subDirectory))
    {
        boost::filesystem::create_directories(subDirectory);
    }
    chdir(subDirectory.c_str());
    remove (fileName.c_str());
    std::ofstream dataFile (fileName);
    dataFile << Value;
    dataFile.close();
}

void readData_String (std::string fileName, std::string &Value, std::string subDirectory)
{
    QString dataDir;
    getDataDir(dataDir);
    chdir(dataDir.toUtf8().data());
    if (!boost::filesystem::is_directory(subDirectory))
    {
        boost::filesystem::create_directories(subDirectory);
    }
    chdir(subDirectory.c_str());
    std::ifstream dataFile (fileName);
    std::getline(dataFile, Value);
    dataFile.close();
}

void readData_Int (std::string fileName, int &Value, std::string subDirectory)
{
    QString dataDir;
    getDataDir(dataDir);
    chdir(dataDir.toUtf8().data());
    if (!boost::filesystem::is_directory(subDirectory))
    {
        boost::filesystem::create_directories(subDirectory);
    }
    chdir(subDirectory.c_str());
    std::ifstream dataFile (fileName);
    dataFile >> Value;
    dataFile.close();
}


//




//define some config varibles
int studentNumber = 40;
int grade = 1;
int Class = 15;
int currentNumber;
int itemNumber;
int currentItem;
int item[100]={1};

//we only want to read config when clicking "open settings" for the first time.
bool ifReadConfig = true;
//default is open settings, after clicking, turn to close settings ...
bool ifOpenSettings = true;
bool ifOpenMainWidget = true; //the same


// ssh-related config strings
std::string host = "127.0.0.1";
std::string username = "user";
std::string password = "1";
//std::string remote_dir = "/home/user/6";
//std::string local_dir = "./";              //define local_dir and remote_dir in parameters, not here
std::string ssh_options = "-o StrictHostKeyChecking=no ";
