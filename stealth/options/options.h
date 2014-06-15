#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <memory>

#include <bobcat/argconfig>
#include <bobcat/linearmap>
#include <bobcat/log>
#include <bobcat/multistreambuf>
#include <bobcat/syslogstream>

#include "../stealthenums/stealthenums.h"

class Options: public StealthEnums
{
    FBB::ArgConfig &d_arg;

    std::unique_ptr<FBB::SyslogStream> d_syslog;
    FBB::Log d_log;

    FBB::MultiStreambuf d_multiStreambuf;
    std::ostream d_msg;                     // d_msg handles all messages to
                                            // syslog and/or d_log

    Mode d_mode = INTEGRITY_SCAN;
    MailType d_mailType = MailType::ON;

    std::string d_policyFilePath;
    std::string d_runFile;

    bool d_reload;
    bool d_rerun;
    bool d_resume;
    bool d_suppress;
    bool d_terminate;
    bool d_keepAlive;
    bool d_randomDelay;

    bool d_repeat;
    size_t d_repeatInterval;
    size_t d_delayInterval;
    size_t d_verbosity;

    FBB::LinearMap<std::string, FBB::Facility>::const_iterator 
                                                        d_syslogFacility;
    FBB::LinearMap<std::string, FBB::Priority>::const_iterator 
                                                        d_syslogPriority;


    static Options *s_options;

    static FBB::Facility    s_defaultSyslogFacility;
    static FBB::Priority    s_defaultSyslogPriority;
    static char const       s_defaultConfigFile[];
    static char const       s_defaultSyslogIdent[];

    static size_t   s_defaultVerbosity;
    static size_t   s_shortestRepeatInterval;

    static FBB::LinearMap<std::string, FBB::Facility> const 
                                                       s_syslogFacilities;
    static FBB::LinearMap<std::string, FBB::Priority> const 
                                                       s_syslogPriorities;

    public:
        static Options &instance();

        Options(Options const &other) = delete;

        bool parseConfigFile() const;
        bool verboseOrJustParse() const;
        bool verbose() const;
        bool ipc() const;
        bool reload() const;        
        bool rerun() const;
        bool terminate() const;
        bool suppress() const;
        bool resume() const;
        bool keepAlive() const;

        Mode mode() const;
        MailType mailType() const;

        size_t repeatInterval() const;
        size_t randomDelay() const;

        std::string const &policyFilePath() const;
        std::string const &basename() const;
        std::string const &runFile() const;

        static void usage(std::string const &progname);

    private:
        Options();

        bool setSyslog();

        std::string syslogTag() const;
        FBB::Priority syslogPriority() const;
        FBB::Facility syslogFacility() const;


        void repeatOption();
        void setRandomDelay();
        void checkAction() const;

        void loadConfigFile();
};

inline Options::Mode Options::mode() const
{
    return d_mode;
}

inline Options::MailType Options::mailType() const
{
    return d_mailType;
}

inline bool Options::reload() const
{   
    return d_reload;
}

inline bool Options::verbose() const
{   
    return d_arg.option('V');
}

inline bool Options::parseConfigFile() const
{   
    return d_arg.option('c');
}

inline bool Options::verboseOrJustParse() const
{   
    return d_arg.option("cd");
}

inline bool Options::rerun() const
{   
    return d_rerun;
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





