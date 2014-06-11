#include "options.ih"

void Options::checkAction() const
{
            // only one of these options may be specified

    if (d_reload + d_rerun + d_resume + d_suppress + d_terminate > 1)
    {
        fmsg << "incompatible options:";

        if (d_reload)
            fmsg << " --reload";

        if (d_rerun)
            fmsg << " --rerun";

        if (d_resume)
            fmsg << " --resume";

        if (d_suppress)
            fmsg << " --suppress";

        if (d_terminate)
            fmsg << " --terminate";
        
        fmsg << endl;
    }
}





