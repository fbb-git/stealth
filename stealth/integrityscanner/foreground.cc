#include "integrityscanner.ih"

void IntegrityScanner::foreground(size_t cmdNr)
{
    cout.clear();

    if (cmdNr > d_policyFile.size())
        imsg << "cannot run policy command #" << cmdNr << " out of " <<
                                            d_policyFile.size() << endl;
    else
    {    
        d_cmdIterator += cmdNr - 1;         // if so, set the cmdIterator
        execute(*d_cmdIterator);            // and execute that command
    }

    cout.setstate(ios::failbit);
}







