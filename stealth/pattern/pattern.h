#ifndef _PATTERN_H_
#define _PATTERN_H_

#include <string>
#include <utility>
#include <regex.h>

namespace FBB
{

class Pattern
{
    public:
        typedef std::pair<std::string::size_type, std::string::size_type>
            Position;

        // define a pattern from a char const *.
        // using a case-flag and number of ()-subexpressions
        Pattern::Pattern(char const *pattern, bool caseSensitive = true,
                         unsigned nSub = 10)
        {
            init(pattern, caseSensitive, nSub);
        }

        // Same, but define a pattern from a string const &
        Pattern::Pattern(std::string const &pattern, bool caseSensitive = true,
                         unsigned nSub = 10)
        {
            init(pattern.c_str(), caseSensitive, nSub);
        }

        ~Pattern();

        bool match(std::string const &text)  // match a string with a pattern
        {                               // true/false depends on matchresult
            return match(text.c_str());
        }
        bool match(char const *text);   // same function, using char const *
                                        // rather than a string

        operator bool() const           // check the validity of a pattern.
        {                               // if false, nothing sensible
            return compiled;            // is returned by other functions
        }
        std::string before() const;          // all text before the matched text

        std::string match() const            // the matched text
        {
            return (*this)[0];
        }
        std::string beyond() const;          // the text beyond the matched text

            // (0) is complete expression,remaining are subexpressions
            // (npos, npos) is returned if index exceeds available indices
            // (which may be 0)
        Position position(unsigned index) const; // position of subexpression

        std::string operator[](unsigned index) const; // subexpression
                                            // empty string for illegal index

        unsigned end() const            // index beyond the last available
        {
            return beyondLast;
        }

    private:
        typedef std::pair<char const *, char const *>
            conversion;

        Pattern(Pattern const &pat);                        // NI
        Pattern const &operator=(Pattern const &pat);       // NI

        void init(char const *pattern, bool caseFlag, unsigned nSub);
        void modify(std::string &pattern, unsigned idx);

        bool
            matched,
            compiled;
        regex_t
            regex;  // use re_nsub: number of subexpressions
        regmatch_t
            *subExpression;
        unsigned
            nSub,
            beyondLast;
        std::string
            text;

        static conversion
            patmod[];
        static unsigned
            sizeofPatmod;
};

}

#endif
