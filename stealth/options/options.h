#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <memory>

#include <bobcat/arg>
//#include <bobcat/log>
//#include <bobcat/multistreambuf>
//#include <bobcat/syslogstream>

#include "../runmode/runmode.h"

//namespace FBB
//{
//    class SyslogStream;
//}

class Options: public RunMode
{
    FBB::Arg &d_arg;

    std::string d_configSorterPath;
    std::string d_runFile;

    bool d_reload;
    bool d_rerun;
    bool d_resume;
    bool d_suppress;
    bool d_terminate;
    bool d_keepAlive;
    bool d_randomDelay;
    bool d_reportToStdout;

    bool d_repeat;
    size_t d_repeatInterval;
    size_t d_delayInterval;

    static size_t const s_shortestRepeatInterval = 60;
    static Options *s_options;

//    static char const       s_defaultConfigFile[];

    public:
        static Options &instance();

        Options(Options const &other) = delete;

        bool ipc() const;
        bool reload() const;        
        bool rerun() const;
        bool terminate() const;
        bool suppress() const;
        bool resume() const;
        bool keepAlive() const;
        bool reportToStdout() const;

        size_t repeatInterval() const;
        size_t randomDelay() const;

        std::string const &configSorterPath() const;
        std::string const &basename() const;
        std::string const &runFile() const;

        static void usage(std::string const &progname);

    private:
        Options();

        void repeatOption();
        void setRandomDelay();
        void checkAction() const;
};

inline bool Options::reload() const
{   
    return d_reload;
}

inline bool Options::rerun() const
{   
    return d_rerun;
}

inline bool Options::reportToStdout() const
{   
    return d_reportToStdout;
}

inline bool Options::terminate() const
{   
    return d_terminate;
}

inline bool Options::suppress() const
{   
    return d_suppress;
}

inline bool Options::resume() const
{   
    return d_resume;
}

inline bool Options::keepAlive() const
{   
    return d_keepAlive;
}

inline bool Options::ipc() const
{   
    return d_reload || d_rerun || d_terminate || d_suppress || d_resume;
}

//inline bool Options::cronfile() const
//{   
//    return d_arg.nArgs();
//}
//
//inline IPCFunction::Function Options::ipcFunction() const
//{   
//    return d_ipcFunction;
//}

inline std::string const &Options::configSorterPath() const
{   
    return d_configSorterPath;
}

inline std::string const &Options::runFile() const
{   
    return d_runFile;
}

inline std::string const &Options::basename() const
{   
    return d_arg.basename();
}

inline size_t Options::repeatInterval() const
{
    return d_repeatInterval;
}

inline size_t Options::randomDelay() const
{
    return d_randomDelay;
}

#endif





