#include "policyfile.ih"

void PolicyFile::loadOptions(istream &configFile)
{
    TempStream tmpStream(User().homedir() + s_configFileBase);

    tmpStream << configFile.rdbuf();                // copy the long options
                                                    // into the temp. stream 
    tmpStream.close();                              

                                        // read the config file's options
    ArgConfig::instance().open(tmpStream.fileName());
}

