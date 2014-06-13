#ifndef INCLUDED_RUNMODE_
#define INCLUDED_RUNMODE_

#include <bobcat/linearmap>

#include "../modeenum/modeenum.h"

struct RunMode: public ModeEnum
{
    private:
        static FBB::LinearMap<Mode, char const *> const s_modeName;
        static FBB::LinearMap<Mode, int> const s_mode2signal;

        Mode  d_mode = INTEGRITY_SCAN;

    public:
        bool mode(Mode query) const;
        Mode mode() const;
        char const *modeName() const;
        int signum() const;     // exception if called without associated 
                                // signal
        void setMode(Mode mode);
        bool stop() const;
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
    return d_mode & mode;
}
        
inline bool RunMode::stop() const
{
    return mode(SUSPEND | TERMINATE);
}
        
inline int RunMode::signum() const
{
    return s_mode2signal.find(d_mode)->second;
}
        
#endif


