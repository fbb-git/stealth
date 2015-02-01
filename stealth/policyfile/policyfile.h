#ifndef _INCLUDED_POLICYFILE_H_
#define _INCLUDED_POLICYFILE_H_

#include <string>
#include <vector>
#include <bobcat/linearmap>
#include <bobcat/configfile>

namespace FBB
{
    class Pattern;
}

class PolicyFile
{
        typedef FBB::LinearMap<std::string, std::string> LinearMap;

        std::string                     d_policyPath;
        size_t                          d_parseOnly;

        FBB::ConfigFile                 d_configfile;
        std::vector<std::string>        d_command;

        LinearMap   d_use;
        LinearMap   d_define;
    
        static std::pair<std::string, std::string> const s_defaultKeyword[];
        static size_t s_nDefaultKeywords;
        static FBB::Pattern              s_firstWord;
        static FBB::Pattern              s_comment;
        static FBB::Pattern              s_define;   // [0]: all text,
                                                // [1]: all ${NAME} text
                                                // [2]: NAME itself
        static FBB::Pattern              s_log; // [4]: name of the logfile

    public:
        PolicyFile(std::string const &policyPath, size_t parseOnly);

        void reload();

        size_t size() const;    
        std::vector<std::string>::const_iterator firstCmd() const;
        std::vector<std::string>::const_iterator beyondCmd() const;
        std::string const &operator[](std::string const &key) const;

        void pathMsg() const;
    
    private:
        void load();

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







