#ifndef INCLUDED_RUNMODE_
#define INCLUDED_RUNMODE_

#include <bobcat/linearmap>

struct RunMode
{
    enum Mode
    {
        ONCE,           // single run 
        KEEP_ALIVE,     // multiple runs
        RERUN,          // rerun every now and then

        RELOAD,         // reload the config files (-> SIGPIPE)

        SUPPRESS,       // suppress a stealth run (-> SIGUSR1)
        SUPPRESSED,     // automatically set after processing  SUPPRESS

        RESUME,         // resume a suppressed Stealth run (-> SIGUSR2)

        TERMINATE,      // terminate a STEALTH run through SIGTERM
        TERMINATED,     // automatically following TERMINATE
    };

    private:
        static FBB::LinearMap<RunMode::Mode, char const *> const s_modeName;
        static FBB::LinearMap<RunMode::Mode, int> const s_mode2signal;

        Mode             d_mode = ONCE;

    public:
        bool mode(Mode query) const;
        Mode mode() const;
        char const *modeName() const;
        int signum() const;     // exception if called without associated 
                                // signal
        void setMode(Mode mode);
                                            // always returns true, or
};

inline char const *RunMode::modeName() const
{
    return s_modeName.find(d_mode)->second;
}

inline RunMode::Mode RunMode::mode() const
{
    return d_mode;
}
        
inline bool RunMode::mode(Mode mode) const
{
    return d_mode == mode;
}
        
inline void RunMode::setMode(Mode mode)
{
    d_mode = mode;
}
        
inline int RunMode::signum() const
{
    return s_mode2signal.find(d_mode)->second;
}
        
#endif


