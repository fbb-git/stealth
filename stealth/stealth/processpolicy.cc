#include "stealth.ih"

// Called by main() once all preliminary actions have been completed. 

void Stealth::processPolicy()
{
    if (d_options.daemon())
        fork();                 // creates the daemon. Its childProcess
    else                        // does the chores.
        doChores();
}
