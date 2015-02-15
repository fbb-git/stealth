#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <string>

#include <bobcat/argconfig>
#include <bobcat/linearmap>

#include <bobcat/log>

#include "../stealthenums/stealthenums.h"
#include "../syslogstruct/syslogstruct.h"

class Options: public StealthEnums
{
    enum FileArgs
    {
        LOG         = 1 << 0,
        SKIP_FILE   = 1 << 1
    };
            
    FBB::ArgConfig &d_arg;

    std::string d_policyPath;
    
    Mode d_mode = INTEGRITY_SCAN;

    std::string d_base;

    std::string d_skipFile;
    std::string d_logName;
    int d_cmdLineOption = 0;

    std::string d_unixDomainSocket;
    std::string d_maxSizeStr;

    bool d_reload;
    bool d_rerun;
    bool d_resume;
    bool d_suspend;
    bool d_terminate;
    bool d_daemon;
    bool d_randomDelay;
    bool d_sendMail = true;
    bool d_logMail  = false;
    bool d_stdout   = false;
    bool d_repeat;
    bool d_foreground;
    bool d_ipc;
    bool d_dryrun;
    size_t d_repeatInterval;
    size_t d_delayInterval  = 0;
    size_t d_commandNr      = 0;
    size_t d_parsePolicy    = 0;
    size_t d_verbosity;

    SyslogStruct d_syslogStruct;


    std::streamsize d_maxDownloadSize = 10 * 1024 * 1024;   // 10 MB

    FBB::LinearMap<std::string, FBB::Facility>::const_iterator 
                                                        d_syslogFacility;
    FBB::LinearMap<std::string, FBB::Priority>::const_iterator 
                                                        d_syslogPriority;

    FBB::TimeStamps  d_timestamp = FBB::UTCTIMESTAMPS;

    static Options *s_options;

    static FBB::Facility    s_defaultSyslogFacility;
    static FBB::Priority    s_defaultSyslogPriority;
    static char const       s_defaultSyslogIdent[];

    static size_t   s_defaultVerbosity;

    static FBB::LinearMap<std::string, FBB::Facility> const 
                                                        s_syslogFacilities;
    static FBB::LinearMap<std::string, FBB::Priority> const 
                                                        s_syslogPriorities;

    static FBB::LinearMap<Mode, char const *> const         s_modeName;

    public:
        Options();

        Options(Options const &other) = delete;

        void oldOptions() const;

        bool verbose() const;
        bool ipc() const;
        bool reload() const;        
        bool rerun() const;
        bool terminate() const;
        bool suspend() const;
        bool resume() const;
        bool daemon() const;
        bool repeat() const;
        bool sendMail() const;

        bool logMail() const;
        void setLogMail();

        bool stdout() const;
        bool dryrun() const;

        Mode mode() const;
        char const *modeRequest() const;

        size_t commandNr() const;
        size_t nextIntegrityScan() const;

        size_t parsePolicy() const;
        size_t verbosity() const;

        std::streamsize maxDownloadSize() const;

        std::string const &basename() const;
        std::string const &maxSizeStr() const;
        std::string const &unixDomainSocket() const;
        std::string const &skipFile() const;
        std::string const &logName() const;
        std::string const &policyFilePath() const;

        std::string rfc2822() const;

        SyslogStruct const &syslogStruct() const;

        FBB::TimeStamps timestamp() const;

        void setConfigOptions();    // set options which may be (re)defined by
                                    // config-files (e.g. the 2nd part of
                                    // policy files 


        static void usage(std::string const &progname);

    private:
        static std::string getCwd();

        void requireSomeArgument();

        void setMode();
        void checkMode() const;

        void setCommandNr();
        void setParsePolicy();

        void setStdout();

        int setLog();               // initially using cmd-line options
        int setSkipFile();          // when set in the policy file use the 
                                    // policy file's base

        void setTimestamp();

        void setRepeat();
        void setRandomDelay();
            size_t checkM(std::string const &spec, char const *option) const;

        size_t randomAddition() const;
        size_t repeatInterval() const;

        void setMail();
        void setDownloadSize();

        void setVerbosity();

        void setSyslog();
        void setSyslogPriority();
        void setSyslogFacility();

        void setPolicyPath();

        void foregroundOnly(char const *optionName) const;
};

inline FBB::TimeStamps Options::timestamp() const
{
    return d_timestamp;
}

inline SyslogStruct const &Options::syslogStruct() const
{
    return d_syslogStruct;
}

inline size_t Options::verbosity() const
{
    return d_verbosity;
}

inline size_t Options::parsePolicy() const
{
    return d_parsePolicy;
}

inline Options::Mode Options::mode() const
{
    return d_mode;
}

inline char const *Options::modeRequest() const
{
    return s_modeName.find(d_mode)->second;
}

inline bool Options::sendMail() const
{
    return d_sendMail;
}

inline bool Options::logMail() const
{
    return d_logMail;
}

inline void Options::setLogMail() 
{
    d_logMail = true;
}

inline bool Options::reload() const
{   
    return d_reload;
}

inline bool Options::verbose() const
{   
    return d_arg.option('V');
}

inline bool Options::rerun() const
{   
    return d_rerun;
}

inline bool Options::repeat() const
{   
    return d_repeat;
}

inline bool Options::terminate() const
{   
    return d_terminate;
}

inline bool Options::suspend() const
{   
    return d_suspend;
}

inline bool Options::resume() const
{   
    return d_resume;
}

inline bool Options::daemon() const
{   
    return d_daemon;
}

inline bool Options::ipc() const
{   
    return d_ipc;
}

inline bool Options::stdout() const
{   
    return d_stdout;
}

inline bool Options::dryrun() const
{   
    return d_dryrun;
}

inline std::string const &Options::policyFilePath() const
{   
    return d_policyPath;
}

inline std::string const &Options::skipFile() const
{   
    return d_skipFile;
}

inline std::string const &Options::logName() const
{   
    return d_logName;
}

inline std::string const &Options::unixDomainSocket() const
{   
    return d_unixDomainSocket;
}

inline std::string const &Options::basename() const
{   
    return d_arg.basename();
}

inline size_t Options::repeatInterval() const
{
    return d_repeatInterval;
}

inline size_t Options::nextIntegrityScan() const
{
    return repeatInterval() + randomAddition();
}

inline size_t Options::commandNr() const
{
    return d_commandNr;
}

inline std::streamsize Options::maxDownloadSize() const
{
    return d_maxDownloadSize;
}

inline std::string const &Options::maxSizeStr() const
{
    return d_maxSizeStr;
}

#endif





