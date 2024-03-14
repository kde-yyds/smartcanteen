#ifndef STANDARDPATH_H
#define STANDARDPATH_H
#endif // STANDARDPATH_H

#include <cstring>
#include <boost/filesystem.hpp>
#include "checkOS.h"

#include <QStandardPaths>

void getConfigDir(QString &configDir)
{
    configDir = QStandardPaths::standardLocations(QStandardPaths::ConfigLocation).first() + "/smartcanteen-client";
    if (!boost::filesystem::is_directory(configDir.toUtf8().data()))
    {
        boost::filesystem::create_directories(configDir.toUtf8().data());
    }
}

void getDataDir(QString &dataDir)
{
    dataDir = QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation).first() + "/smartcanteen-client";
    /*char *dataDir = new char[100];
    strcpy(dataDir,"");
    strcat(dataDir,getHomeDir());
    strcat(dataDir,"/.local/share/smartcanteen-client");
    if (!boost::filesystem::is_directory(dataDir))
    {
        boost::filesystem::create_directories(dataDir);
    }
    return dataDir;*/
    if (!boost::filesystem::is_directory(dataDir.toUtf8().data()))
    {
        boost::filesystem::create_directories(dataDir.toUtf8().data());
    }
}
