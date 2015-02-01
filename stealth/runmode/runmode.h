#ifndef INCLUDED_RUNMODE_
#define INCLUDED_RUNMODE_

#include <iostream>
#include <bobcat/linearmap>

#include "../stealthenums/stealthenums.h"

struct RunMode: public StealthEnums
{
    friend std::ostream &operator<<(std::ostream &out, RunMode const &mode);

    private:
        static FBB::LinearMap<Mode, char const *> const s_modeName;

        volatile Mode  d_mode = INTEGRITY_SCAN;

    public:
        bool hasMode(Mode query) const;
        Mode mode() const;

        void setMode(Mode mode);

        static Mode validate(int mode);
};

inline RunMode::Mode RunMode::validate(int mode)
{
    return 
        ((mode - 1)  & mode) == 0 
        && 
        mode <= UNKNOWN ?
            static_cast<Mode>(mode)
        :
            UNKNOWN;
}

inline RunMode::Mode RunMode::mode() const
{
    return d_mode;
}
        
inline bool RunMode::hasMode(Mode mode) const
{
    return d_mode & mode;
}

inline std::ostream &operator<<(std::ostream &out, RunMode const &mode)
{
    return out << RunMode::s_modeName.find(mode.mode())->second;
}
        
#endif


