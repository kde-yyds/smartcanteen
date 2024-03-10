#ifndef STANDARDPATH_H
#define STANDARDPATH_H
#include <iostream>
#endif // STANDARDPATH_H

#include <string>
#include <cstring>
#include <boost/filesystem.hpp>
#include "checkOS.h"

//TODO:use QStandardPaths


char* getHomeDir()
{
    if(isLinux() == true)
        return getenv("HOME");
    else
        return NULL;////TODO: get home dir on windows
}

char* getConfigDir()
{
    char *configDir = new char[100];
    strcpy(configDir,""); // workaround problem:configDir not clean (may contain config string) before clearing it
    strcat(configDir,getHomeDir());

    //std::cout<<"getHomeDir="<<getHomeDir()<<std::endl<<"configDir="<<configDir<<std::endl;

    strcat(configDir,"/.config/smartcanteen-client");

    //std::cout<<"configDir="<<configDir<<std::endl;

    if (!boost::filesystem::is_directory(configDir))
    {
        boost::filesystem::create_directories(configDir);
    }
    return configDir;
}

char* getDataDir()
{
    char *dataDir = new char[100];
    strcpy(dataDir,"");
    strcat(dataDir,getHomeDir());
    strcat(dataDir,"/.local/share/smartcanteen-client");
    if (!boost::filesystem::is_directory(dataDir))
    {
        boost::filesystem::create_directories(dataDir);
    }
    return dataDir;
}
