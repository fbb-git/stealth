#ifndef _INCLUDED_ARG_H_
#define _INCLUDED_ARG_H_

/*
        Singleton Class built around getopt() and getopt_long() (3)

        Arg(char const *optstring, int argc, char **argv):

        Arg(char const *optstring, 
            unsigned nLongOptions, Arg::LongOption const *longOptions, 
            int argc, char **argv):

            construct the Arg object. Multiple constructions will (silently)
            result in the same object: after the first object has been
            constructed, remaining construction requests are ignored.

        Arg() 
            makes an already initialized  argument object available. Throws an
            Errno exception if Arg hasn't been initialized yet.

            optstring: "ab:" :  a may be present (-a),
                                b may be present, to be followed by an arg.


            Long arguments are specified as follows:

            1. Construct an array 
                    Arg::LongOption longOptions[] = { c1, c2, ... cn }
                where c1, c2, ..., cn are constructor invocations of 
                Arg::LongOption() constructors
            2. Pass 
                    sizeof(longOptions) / sizeof(Arg::LongOption), longOptions
                as 2nd and 3rd argument of the second constructor of Arg
            
            Arg::LongOption() objects may be constructed using the following
                        constructors: 

            Arg::LongOption(char const *name, Arg::Type type = None) 
                                Defines a long argument by its name
                                The argument type may be:
                                    None - no argument is associated
                                    Required - required argument
                                    Optional - optional argument
                                               (when present, it's used)

            Arg::LongOption(char const *name, int optionChar) 
                                Defines a long argument by its name
                                Its value is associated with the option value
                                `optionChar'. `optionChar' must also have been
                                defined as a single-character option, 
                                and the long option handles arguments 
                                identically as the single character argument.
                

        string const &basename(): returns the basename of the program

        unsigned nArgs(): number of arguments left after option-removal,
                                 The program name (argv[0]) is NOT counted 
                                 here.

        unsigned nOptions(): number of single character options

        unsigned nLongOptions(): number of long options

        bool option(string *value, char const *option): 
                                    returns true if the long argument was
                                    present. If an (optional) argument was
                                    defined, its argument is stored 
                                    in `value'. If `value' is returned as an
                                    empty string an optional argument was not
                                    provided. If no argument was defined for
                                    this long argument, `value' may be
                                    specified as 0. The function throws an
                                    EINVAL (Invalid argument) exception if
                                    0 was provided but the option has an
                                    (optional) argument.
                                    

        bool option(int option):    returns true/false, if `option' 
                                    was/was not present

        bool option(std::string const &options):    returns true, 
                                    if at least one of the options specified
                                    in the argument `option' were present

        bool option(int option, string &value): same and stores its argument
                                    in `value'. DEPRECATED. USE:

        bool option(string *value, int option): same and stores its argument
                                    in `*value'


        char const *operator[](unsigned idx): returns argument[x], after
                                    removing the options. 0 if no arg[x]
                                    is available. The program name (argv[0])
                                    is NOT counted here. Here, index 0
                                    refers to the first ARGUMENT, i.e.,
                                    the program's argv[1].
                            
*/


#ifndef _SYSINC_STRING_
#include <string>
#define _SYSINC_STRING_
#endif

#ifndef _SYSINC_GETOPT_H_
#include <getopt.h>
#define _SYSINC_GETOPT_H_
#endif

#ifndef _SYSINC_VECTOR_
#include <vector>
#define _SYSINC_VECTOR_
#endif

#ifndef _SYSINC_UNISTD_H_
#include <unistd.h>
#define _SYSINC_UNISTD_H_
#endif

namespace FBB
{
    class OptStructArray;
    class Arg
    {
        typedef std::pair<int, std::string>         IntStringPair;
        typedef std::pair<std::string, std::string> StringStringPair;
        typedef struct option                       OptStruct;

        static Arg                      *s_arg;
        static std::string              s_dirsep;

        std::vector<std::string>        d_argv;
        std::vector<IntStringPair >     d_optv;
        std::vector<StringStringPair>   d_longOption;
        std::string                     d_base;
        
        public:
            enum Type
            {
                None        = 0,
                Required    = 1,
                Optional    = 2,
                AsCharOption,
            };

            class LongOption
            {
                std::string d_name;
                Arg::Type   d_type;
                int         d_optionChar;
                
                friend class Arg;
                
                public:
                    LongOption(char const *name, Arg::Type type = None);
                    LongOption(char const *name, int optionChar);

                    std::string const &getName() const
                    {
                        return d_name;
                    }
            };

            static void initialize(char const *optstring, int argc, 
                                                            char **argv);
            static void initialize(char const *optstring,
                                    LongOption const * const begin,
                                    LongOption const * const end,
                                    int argc, char **argv);
            static Arg &getInstance();        

            std::string const &basename() const
            {
                return d_base;
            }
            inline unsigned nArgs() const
            {
                return d_argv.size();
            }
            inline unsigned nOptions() const
            {
                return d_optv.size();
            }
            inline unsigned nLongOptions() const
            {
                return d_longOption.size();
            }
            bool option(int option) const
            {
                return findopt(option) != nOptions();
            }
            bool option(int option, std::string &value) const;  // 2 DEPRECATED
            bool option(std::string const &optchars) const;     // 3
            bool option(std::string *value, int option) const;  // 4
                                                                // 5
            bool option(std::string *value, char const *longOption) const;
    
            char const *operator[](unsigned idx) const;

        private:
            Arg(Arg const &other);                              // NI
            Arg &operator=(Arg const &other);                   // NI

            Arg(char const *optstring, int argc, char **argv);  // 1

            Arg(char const *optstring,                          // 2
                LongOption const * const begin,
                LongOption const * const end,
                int argc, char **argv);


            unsigned findopt(int optchar) const;     
            unsigned findopt(char const *longOption) const;     
            void setBasename(std::string const &argv0);
            void fillLongOptions(
                            OptStruct *optStructs,
                            std::string const &optString,
                            LongOption const * const begin,
                            LongOption const * const end);
            void addLongOption(OptStruct *optStructs,
                            std::string const &optString,
                            LongOption const &longOption);
            int setOptionType(std::string const &optString,
                            LongOption const &longOption);
            bool plainLongOption(int *c, 
                            LongOption const &longOption);
    };

}

#endif
