#include "reporter.ih"

// This function is called from Stealth::performTasks() at the beginning of
// the policy file processing loop. It (re)opens the report file and prepares
// it for the next run.

#include <bobcat/stat>

void Reporter::newReport()
{
//    if (!Lock::lockRunFile(Lock::NONBLOCKING))  // wait for the lock on an 
//        return;                                 // existing run file. 
//                                                // No run file: no lock

    if (not Stat(d_name))
        cerr << d_name << " does not exist\n";

    d_out.close();
    d_out.open(d_name.c_str(), ios::out | ios::ate | ios::in);

cerr << "NEWREPORT " << d_name << " opens at " << d_out.tellp() << '\n';

    if (!d_out)
    {
        d_out.clear();
        Exception::open(d_out, d_name, ios::out | ios::in | ios::trunc);    
    }

    reinit();
}





