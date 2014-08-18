#ifndef INCLUDED_RUNMODE_
#define INCLUDED_RUNMODE_

#include <bobcat/linearmap>

#include "../stealthenums/stealthenums.h"

struct RunMode: public StealthEnums
{
    private:
        static FBB::LinearMap<volatile Mode, char const *> const s_modeName;
        static FBB::LinearMap<volatile Mode, int> const s_mode2signal;

        volatile Mode  d_mode = INTEGRITY_SCAN;

    public:
        bool mode(Mode query) const;
        Mode mode() const;
        char const *modeName() const;

        void setMode(Mode mode);
        bool interrupted() const; // a running integrity scan was interrupted
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
        
inline bool RunMode::interrupted() const
{
    return mode(SUSPEND | TERMINATE | RELOAD);
}
        
#endif


