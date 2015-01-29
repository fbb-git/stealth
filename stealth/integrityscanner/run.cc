#include "integrityscanner.ih"

void IntegrityScanner::run()
{
    d_active = true;

    ++d_nScans;

    setSentinel();                              // determine d_sentinel

    d_cmdIterator = d_policyFile.firstCmd();        // d_cmdIterator is set to
                                                // the first command. It's a
                                                // true iterator, so we can 
                                                // add values to it, below.

    if (size_t cmdNr = d_options.commandNr())   // is there  a command number?
        foreground(cmdNr);                      // run it in the foreground
    else                                        // no number: process all
    {                                           // commands    
        auto beyond = d_policyFile.beyondCmd();

        for (auto &cmd: ranger(d_cmdIterator, beyond))
        {
            if (not d_active)                   
            {
                m1 << "integrity scan interrupted by " << 
                            d_task.modeName() << " request" << endl;
                return;
            }

            execute(cmd);
        }
    }

    m3 << "policy file processed" << endl;
    d_active = false;
}





