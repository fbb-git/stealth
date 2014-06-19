#include "options.ih"

void Options::setDownloadSize()
{
    if (not d_arg.option(&d_maxSizeStr, "max-size"))
        return;

    if (d_ipc)
    {
        warnOption("--max-size ignored");
        return;
    }

    size_t pos;
    try
    {
        d_maxDownloadSize = stoull(d_maxSizeStr, &pos);

        switch (int ch = toupper(d_maxSizeStr[pos]))
        {
            case 'G':
                d_maxDownloadSize *= 1024;
            // FALLING THRU

            case 'M':
                d_maxDownloadSize *= 1024;
            // FALLING THRU

            case 'K':
                d_maxDownloadSize *= 1024;
            // FALLING THRU
    
            default:
                if (ch == 'B' || pos == d_maxSizeStr.length())
                    return;
            break;
        }
    }
    catch (...)
    {}

    fmsg << "--max-size " << d_maxSizeStr << ": invalid option value" << endl;
}



