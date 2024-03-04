#ifndef STANDARDPATH_H
#define STANDARDPATH_H
#endif // STANDARDPATH_H

#include <string>
#include <cstring>
#include <boost/filesystem.hpp>
#include "checkOS.h"

char* getHomeDir()
{
    if(isLinux() == true)
        return getenv("HOME");
    else
        return NULL;//TODO: get home dir on windows
}

char* getConfigDir()
{
    char *configDir = new char[100];
    strcat(configDir,getHomeDir());
    strcat(configDir,"/.config/smartcanteen-client");
    if (!boost::filesystem::is_directory(configDir))
    {
        boost::filesystem::create_directories(configDir);
    }
    return configDir;
}

char* getDataDir()
{
    char *dataDir = new char[100];
    strcat(dataDir,getHomeDir());
    strcat(dataDir,"/.local/share/smartcanteen-client");
    if (!boost::filesystem::is_directory(dataDir))
    {
        boost::filesystem::create_directories(dataDir);
    }
    return dataDir;
}
