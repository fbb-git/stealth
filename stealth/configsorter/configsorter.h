#ifndef _ConfigSorter_H_
#define _ConfigSorter_H_

#include <string>
#include <vector>
#include <bobcat/hash>

namespace FBB
{
    class Arg;
    class ConfigFile;
    class Pattern;

    class ConfigSorter
    {
        ConfigFile                  &d_configfile;
        std::vector<std::string>    d_command;
        HashString<std::string>     d_use;
        HashString<std::string>     d_define;
    
        static std::pair<std::string, std::string> const s_defaultKeyword[];
        static unsigned s_nDefaultKeywords;

    public:
        ConfigSorter(ConfigFile &configfile);

        std::vector<std::string>::const_iterator firstCmd()
        {
            return d_command.begin();
        }

        std::vector<std::string>::const_iterator beyondCmd()
        {
            return d_command.end();
        }

        std::string const &operator[](std::string const &key)
        {
            return d_use[key];
        }

    private:
        std::string const &getDEFINE(std::string const &key)
        {
            return d_define[key];
        }

        bool  hasDEFINE(std::string const &key)
        {
            return d_define.count(key);
        }

        void fetchCwd();            // determine current working directory
        void fetchCommands();
                                    // replaces the DEFINE's in text
        void replaceDefines(std::string &text); 
        void insert(HashString<std::string> &hash, Pattern &pattern,
                                                   std::string const &line);
    };

}

#endif
