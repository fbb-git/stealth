#include "options.ih"

string Options::rfc2822() const
{
    return DateTime(
                d_timestamp == UTCTIMESTAMPS ? 
                    DateTime::UTC 
                :
                    DateTime::LOCALTIME
            ).rfc2822();
}
