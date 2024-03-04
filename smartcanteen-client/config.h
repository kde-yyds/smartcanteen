#ifndef CONFIG_H
#define CONFIG_H

#endif // CONFIG_H

#include <string>
#include <fstream>

#include "standardPath.h"

void writeConfig_String (std::string fileName,std::string Value)
{
    chdir (getConfigDir());
    remove (fileName.c_str());
    std::ofstream configFile (fileName);
    configFile << Value;
}
