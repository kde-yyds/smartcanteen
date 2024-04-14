#ifndef PATH_H
#define PATH_H

#endif // PATH_H

#include <boost/filesystem.hpp>

#include <QString>

/*
 * requirements:
 * /opt/smartcanteen    user@archlinux-114514 ~> ll /opt/smartcanteen/
                        总计 0
                        drwxr-xr-x 1 user user  8  4月13日 23:12 list/
                        drwsrwxrwx 1 root root 58  3月17日 21:57 remote/
 *
 * sshd enabled
 *                      user@archlinux-114514 ~> systemctl status sshd
                        ● sshd.service - OpenSSH Daemon
                             Loaded: loaded (/usr/lib/systemd/system/sshd.service; enabled; preset: disabled)
                             Active: active (running) since Sun 2024-04-14 21:30:47 CST; 30min ago
                             Main PID: 694 (sshd)
                             Tasks: 1 (limit: 18096)
                             Memory: 2.2M (peak: 21.1M)
                             CPU: 96ms
                             CGroup: /system.slice/sshd.service
                                     └─694 "sshd: /usr/bin/sshd -D [listener] 0 of 10-100 startups"

 *
*/


/*
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
*/  //the original code from client code. no need to use QStandardPaths because we only want the server to be GNU/Linux.

void getDataDir(std::string &dataDir)
{
    dataDir = "/opt/smartcanteen/list/";
}
