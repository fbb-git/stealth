#include "policyfile.ih"

void PolicyFile::loadOptions(ConfigFile &configFile, size_t from)
{
    TempStream tmpStream(User().homedir() + s_configFileBase);

    for 
    (
        auto begin = configFile.begin() + from, end = configFile.end();
            begin != end;
                ++begin
    )
        tmpStream << *begin << '\n';                // copy the long options
                                                    // into the temp. stream 

    tmpStream.close();                              

                                        // read the config file's options
    ArgConfig::instance().open(tmpStream.fileName());
}

