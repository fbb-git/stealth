#ifndef INCLUDED_STEALTHENUMS_
#define INCLUDED_STEALTHENUMS_

#include <iosfwd>

struct StealthEnums
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

    enum class MailType
    {
        OFF,
        ON,
        LOG
    };

    static std::ostream &leave(std::ostream &out);
};

inline constexpr StealthEnums::Mode operator|(
                                    StealthEnums::Mode lhs, StealthEnums::Mode rhs)
{
    return static_cast<StealthEnums::Mode>(
                static_cast<size_t>(lhs) | static_cast<size_t>(rhs) 
            );
}

        
#endif
