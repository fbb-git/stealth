#ifndef INCLUDED_STEALTHENUMS_
#define INCLUDED_STEALTHENUMS_

#include <iosfwd>

struct StealthEnums
{
    enum Mode       // uses bit-flags values
    {
        INTEGRITY_SCAN  = 1 << 1,   // perform an integrity scan

        RERUN           = 1 << 4,   // rerun on request at WAITING 

        SUSPEND         = 1 << 2,   // suspend a stealth run 

        RESUME          = 1 << 5,   // resume at WAITING 

        RELOAD          = 1 << 6,   // reload the config files 

        TERMINATE       = 1 << 7,   // terminate a Stealth run

        UNKNOWN         = 1 << 8,   
    };
};

inline constexpr StealthEnums::Mode operator|(
                            StealthEnums::Mode lhs, StealthEnums::Mode rhs)
{
    return static_cast<StealthEnums::Mode>(
                static_cast<size_t>(lhs) | static_cast<size_t>(rhs) 
            );
}

#endif
