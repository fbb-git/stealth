#ifndef _INCLUDED_CONFIGFILE_H_
#define _INCLUDED_CONFIGFILE_H_

/*
    Lines are stored with initial WS removed.
    If a line ends in \, then the next line (initial WS removed)
    is appended to the current line.
    All information at and beyond the first # is ignored unless
    the keepComment flag is given.
    Then, lines containing only blanks and tabs are not stored

    The get(param) member returns the line containing `param' as the
    first word that is not immediately followed by alphanumeric chars.
    (in 'param hello' `par' is not found, but `param' is).

    ignorecase: the keyword given in the find() command is case insensitive
*/

#ifndef _SYSINC_VECTOR_
#include <vector>
#define _SYSINC_VECTOR_
#endif

#ifndef _SYSINC_STRING_
#include <string>
#define _SYSINC_STRING_
#endif

namespace FBB
{

class ConfigFile
{
    bool d_keepComment;
    bool d_ignoreCase;
    bool d_status;
    std::vector<std::string> d_lines;

    public:
        ConfigFile(char const *stream,          // Name of config file
                    bool keepComment = false,
                    bool ignoreCase = true);

                                                // get a parameter (or 0)
        char const *get(std::string const &param) const;

                                                // get that line (or 0)
        char const *operator[](unsigned idx) const
        {
            return idx < size() ? d_lines[idx].c_str() : 0;
        }

        unsigned size() const                   // number of non-blank lines
        {
            return d_lines.size();
        }
        operator bool() const                   // return the status of the
        {                                       // initialization
            return d_status;
        }
    private:
        bool find(std::string const &param, std::string const *line) const;
                                                // return the next line
        bool nextLine(std::istream &str, std::string &line);

        ConfigFile(ConfigFile const &other);            // NI
        ConfigFile &operator=(ConfigFile const &other); // NI

};

}

#endif

