#ifndef INCLUDED_MODEENUM_
#define INCLUDED_MODEENUM_

#include <iosfwd>

struct ModeEnum
{
    enum Mode       // uses bit-flags values
    {
        LEAVE           = 1 << 0,

        INTEGRITY_SCAN  = 1 << 1,   // perform an integrity scan

        WAIT            = 1 << 3,   // waiting for another signal/tine

        RERUN           = 1 << 4,   // rerun at WAITING on request (-> SIGHUP)

        SUSPEND         = 1 << 2,   // suppress a stealth run (-> SIGUSR1)

        RESUME          = 1 << 5,   // resume at WAITING (-> SIGUSR2)

        RELOAD          = 1 << 6,   // reload the config files (-> SIGPIPE)

        TERMINATE       = 1 << 7,   // terminate a Stealth run (-> SIGTERM,
                                    //                             SIGINT)
    };

    static std::ostream &leave(std::ostream &out);
};

inline constexpr ModeEnum::Mode operator|(
                                    ModeEnum::Mode lhs, ModeEnum::Mode rhs)
{
    return static_cast<ModeEnum::Mode>(
                static_cast<size_t>(lhs) | static_cast<size_t>(rhs) 
            );
}

        
#endif
