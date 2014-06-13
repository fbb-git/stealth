#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <memory>

#include <bobcat/arg>
//#include <bobcat/log>
//#include <bobcat/multistreambuf>
//#include <bobcat/syslogstream>

#include "../modeenum/modeenum.h"

class Options: public ModeEnum
{
    FBB::Arg &d_arg;

    Mode d_mode = INTEGRITY_SCAN;

    std::string d_policyFilePath;
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

    public:
        static Options &instance();

        Options(Options const &other) = delete;

        bool parseConfigFile() const;
        bool debugOrJustParse() const;
        bool debug() const;
        bool ipc() const;
        bool reload() const;        
        bool rerun() const;
        bool terminate() const;
        bool suppress() const;
        bool resume() const;
        bool keepAlive() const;
        bool reportToStdout() const;

        Mode mode() const;

        size_t repeatInterval() const;
        size_t randomDelay() const;

        std::string const &policyFilePath() const;
        std::string const &basename() const;
        std::string const &runFile() const;

        static void usage(std::string const &progname);

    private:
        Options();

        void repeatOption();
        void setRandomDelay();
        void checkAction() const;
};

inline Options::Mode Options::mode() const
{
    return d_mode;
}

inline bool Options::reload() const
{   
    return d_reload;
}

inline bool Options::debug() const
{   
    return d_arg.option('d');
}

inline bool Options::parseConfigFile() const
{   
    return d_arg.option('c');
}

inline bool Options::debugOrJustParse() const
{   
    return d_arg.option("cd");
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

inline std::string const &Options::policyFilePath() const
{   
    return d_policyFilePath;
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





