#include "stealth.ih"

// called by processPolicy and childProcess

void Stealth::performTasks()
{
    allocateUniquePtrs();

    setupSignals();

    d_integrityScanner->startCommandShells(); 

    while (true)
    {
        Mode request = d_run.mode();

        imsg << "NEXT TASK: " << d_run.modeName() << endl;
    
        if (request == LEAVE)
            break;

        d_reporter->newReport();
                                            // perform the requested task
        (this->*(s_task.find(request)->second))();    
        mailReport();

        if (not d_run.stop())
            d_ipc.wait();                   // wait for the next request
    }
}
        
//    
//    while (true)
//    {
//        d_reporter->standby();      // locks the runfile, opens the report
//                                    // file
//        processRunMode();
//
//
//        mailReport();
//
//        if (!d_reporter->relax())   // close the report file, unlock the run
//            throw Exception();      // file. If the reporter has set
//                                    // d_continue to false, then terminate.
//                                    // This happens when a (remote) 
//                                    // command returns a non-zero exit value.
//
//        if (mode(TERMINATED) || mode(ONCE))
//            break;
//
//        if (mode(RELOAD))
//        {
//            setMode(KEEP_ALIVE);
//            continue;
//        }
//
//        if (mode(SUSPENDED))
//        {
//            imsg << "Supressed. Now signal back the suppressor" << endl;
//
//            d_ipc.sleep(1);         // This delay is necessary to allow the
//                                    // suppressor to start waiting once it has
//                                    // signalled this process. See
//                                    // signalStealth(). 
//
//                                    // let the process that issued
//                                    // `--suppress' know we're done.
//            if (d_ipc.signalSuppressor())
//                imsg << "Wait for --resume..." << endl;
//            else
//                imsg << "Suppressor not signalled: can't read `" <<
//                        Lock::runFilename() << '\'' << endl;
//        }
//
//        do
//        {
//            setDelay();
//            d_ipc.wait();
//        }
//        while (mode(SUSPENDED));
//    }        
// }





