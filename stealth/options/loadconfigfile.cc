#include "options.ih"

void Options::loadConfigFile()
{
    string configFile;
    if (not d_arg.option(&configFile, 'c'))
    {
        configFile = User().homedir() + s_defaultConfigFile;
        if (access(configFile.c_str(), R_OK) != 0)
            configFile.clear();
    }
    if (not configFile.empty())
        d_arg.open(configFile);     // read the arg config file
}
