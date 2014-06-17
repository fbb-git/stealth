#include "stealth.ih"

// called by processPolicy and childProcess

void Stealth::doChores()
{
    policyDepDataMembers();

    setupSignals();

    d_integrityScanner->startCommandShells(); 

    while (true)
    {
        Mode request = d_run.mode();

        if (request == LEAVE)
            break;

        m1 << "\n"
              "SIGNAL: " << d_run.modeName() << endl;
    
        d_stealthLog.header();

        try
        {                                   // perform the requested task
            (this->*(s_task.find(request)->second))();
        }
        catch (Mode mode)
        {
            terminate();
        }

        mailLogs();

        if (d_run.mode(WAIT))
        {
            d_ipc.timedWait();              // wait for the next request
            if (d_run.mode(WAIT))
                d_run.setMode(INTEGRITY_SCAN);
        }
    }
}
