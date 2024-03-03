#ifndef STANDARDPATH_H
#define STANDARDPATH_H
#endif // STANDARDPATH_H

#include <string>
#include <cstring>
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
    char *configDir = new char[50];
    strcat(configDir,getHomeDir());
    strcat(configDir,"/.config/");
    return configDir;
}
