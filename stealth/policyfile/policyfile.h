#ifndef _INCLUDED_POLICYFILE_H_
#define _INCLUDED_POLICYFILE_H_

#include <string>
#include <vector>
#include <bobcat/linearmap>

class Options;

namespace FBB
{
    class Pattern;
    class ConfigFile;
}

class PolicyFile
{
    typedef FBB::LinearMap<std::string, std::string> LinearMap;

    Options &d_options;

    std::vector<std::string>        d_command;

    LinearMap   d_use;
    LinearMap   d_define;

    static char const               s_configFileBase[];

    static std::pair<std::string, std::string> const s_defaultKeyword[];
    static size_t s_nDefaultKeywords;

    static FBB::Pattern              s_firstWord;
    static FBB::Pattern              s_comment;
    static FBB::Pattern              s_define;   // [0]: all text,
                                            // [1]: all ${NAME} text
                                            // [2]: NAME itself
    static FBB::Pattern              s_log; // [4]: name of the logfile

    public:
        PolicyFile(Options &options);

        size_t size() const;    
        std::vector<std::string>::const_iterator firstCmd() const;
        std::vector<std::string>::const_iterator beyondCmd() const;

        std::string const &operator[](std::string const &key) const;

        void chdirBase() const;

    private:
        void load();
        void loadOptions(FBB::ConfigFile &configFile, size_t from);

        std::string const &getDEFINE(std::string const &key) const;
        bool  hasDEFINE(std::string const &key) const;

        void directivesAndCommands();

        void fetchCwd();            // determine current working directory
        void fetchCommands();
                                    // replaces the DEFINE's in text
        void replaceDefines(std::string &text); 
        void insert(LinearMap &linMap, std::string const &line);

        void fixRelativeLocations();
};

inline size_t PolicyFile::size() const
{
    return d_command.size();
}

inline std::vector<std::string>::const_iterator PolicyFile::firstCmd() const
{
    return d_command.begin();
}

inline std::vector<std::string>::const_iterator 
                                            PolicyFile::beyondCmd() const
{
    return d_command.end();
}

inline std::string const &PolicyFile::operator[](
                                                std::string const &key) const
{
    return d_use.find(key)->second;
}

#endif







