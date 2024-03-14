#ifndef STANDARDPATH_H
#define STANDARDPATH_H
#endif // STANDARDPATH_H

#include <boost/filesystem.hpp>

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
    if (!boost::filesystem::is_directory(dataDir.toUtf8().data()))
    {
        boost::filesystem::create_directories(dataDir.toUtf8().data());
    }
}
