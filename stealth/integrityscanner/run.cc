#include "integrityscanner.ih"

void IntegrityScanner::run()
{
    ++d_nScans;

    setSentinel();                              // determine d_sentinel

    d_cmdIterator = d_policyFile.firstCmd();        // d_cmdIterator is set to
                                                // the first command. It's a
                                                // true iterator, so we can 
                                                // add values to it, below.
    string cmdNr;

    if (d_arg.option(&cmdNr, 'r'))              // is there  a command number?
    {
                                                // if so, add its number to
        d_cmdIterator += stol(cmdNr) - 1;       // d_cmdIterator    

        execute(*d_cmdIterator);                // and execute that command
    }
    else                                        // no number: process all
    {                                           // commands    
        auto beyond = d_policyFile.beyondCmd();

        for (auto &cmd: ranger(d_cmdIterator, beyond))
        {
            if (d_run.interrupted())    // terminate, suspend, reload
            {
                imsg << "Running integrity scan interrupted by " << 
                            d_run.modeName() << " request" << endl;
                return;
            }

            execute(cmd);   // *d_cmdIterator);
        }
    }

    if (d_arg.option('d'))
        cerr << "Stealth: policy file processed\n";
}





