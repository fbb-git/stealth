#ifndef _ConfigSorter_H_
#define _ConfigSorter_H_

#include <string>
#include <vector>
#include <bobcat/hash>
#include <bobcat/configfile>

namespace FBB
{
    class Pattern;
}

class ConfigSorter
{
        FBB::ConfigFile                 d_configfile;
        std::vector<std::string>        d_command;
        FBB::HashString<std::string>    d_use;
        FBB::HashString<std::string>    d_define;
    
        static std::pair<std::string, std::string> const s_defaultKeyword[];
        static size_t s_nDefaultKeywords;
        static FBB::Pattern              s_firstWord;
        static FBB::Pattern              s_comment;
        static FBB::Pattern              s_define;   // [0]: all text,
                                                // [1]: all ${NAME} text
                                                // [2]: NAME itself
    public:
        ConfigSorter(char const *confFname);
    
        std::vector<std::string>::const_iterator firstCmd() const;
        std::vector<std::string>::const_iterator beyondCmd() const;
        std::string const &operator[](std::string const &key) const;
    
    private:
        std::string const &getDEFINE(std::string const &key) const;
        bool  hasDEFINE(std::string const &key) const;

        void fetchCwd();            // determine current working directory
        void fetchCommands();
                                    // replaces the DEFINE's in text
        void replaceDefines(std::string &text); 
        void insert(FBB::HashString<std::string> &hash, FBB::Pattern &pattern,
                    std::string const &line);
};

inline std::vector<std::string>::const_iterator ConfigSorter::firstCmd() const
{
    return d_command.begin();
}

inline std::vector<std::string>::const_iterator 
                                            ConfigSorter::beyondCmd() const
{
    return d_command.end();
}

inline std::string const &ConfigSorter::operator[](
                                                std::string const &key) const
{
    return d_use.find(key)->second;
}

#endif







