#include "options.ih"

void Options::setTimestamp()
{
    string value;
    if (not d_arg.option(&value, 't'))
        return;

    if (value == "LT")
        d_timestamp = TIMESTAMPS;
    else if (value == "UTC")
        d_timestamp = UTCTIMESTAMPS;
    else if (value != "UTC")
        wmsg << "--time-stamp " << value << " not supported. Using UTC" <<
                                                                    endl;
}

