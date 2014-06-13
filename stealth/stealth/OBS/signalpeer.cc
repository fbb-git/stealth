//#include "stealth.ih"
//
//// getPid() obtains the process-id from an existing lock-file. The file must
//// exist and the pid stored in the lock-file must be the process-id of an
//// existing Stealth program. This is verified by sending a signal to the
//// corresponding process. If this fails, the lock-file is apparently stale. It
//// is removed and an error message is issued.
//
//// The following signals are used (and processed by IntegrityScanner::processSignal())
//// SIGPIPE: reload configuration files
//// SIGTERM: terminate stealth
//// SIGHUP:  rerun stealth
//// SIGUSR1: suppress stealth from starting a new run
//// SIGUSR2: resume normal actions. 
//
//bool Stealth::signalPeer(int signum, string const &filename)
//{
//    size_t pid = getPid(filename);    // get the pid of the process to signal 
//    if (pid == 0)
//    {
//        imsg << "Can't read `" << filename << "', no process "
//                "to send " << signame << " to" << endl;
//        throw 1;
//    }
//
//    imsg << "Sending " << signame << " to process " << pid << endl;
//
//    // When suppressing (SIGUSR1) we must add this process' ID to the runfile
//    // so the suppressed stealth process can signal back that it has completed
//    // its suppression tasks. Note that this process still has the lock, which
//    // must be removed first before the suppressed stealth process may
//    // continue. 
//    if (signum == SIGUSR1)          // --suppress
//    {
//        ofstream runFile;
//        Exception::open(runFile, Lock::runFilename());  // rewrite the runfile
//    
//        runFile << pid << '\n' <<
//                   getpid() << '\n';// add this process's id to the runfile
//
//        runFile.close();            // done. The runfile now contains the
//                                    // signalled process ID and the current
//                                    // process ID 
//
//                                    // install the reply handler.
//        signal(SIGUSR1, handleReplySignal);
//    }
//
//    sendSignal(signum, signame, pid);   // signal the running stealth, but we
//                                    // still have the lock. It will disappear
//                                    // when  this process terminates, so below
//                                    // it must be explicitly removed when
//                                    // we're suppressing, and are waiting for
//                                    // the reply signal
//
//
//    if (signum == SIGUSR1)              // when suppressing (SIGUSR1)
//    {
//        imsg << "Suppressing process " << pid << endl;
//
//        sleep();                        // Prepare to go to sleep, by setting
//                                        // s_selector
//
//        Lock::unlockRunFile();      // Remove the lock, allow the
//                                    // suppressed process to continue
//                                    // The suppressed process will wait 
//                                    // for a second allowing this process
//                                    // to start its waiting cycle.
//        imsg << "Waiting for the suppressed process to finish its task" << 
//                                                                        endl;
//
//        try                             // see wait() for the try {...
//        {
//            s_selector.wait();          // no need to use wait() here, 
//        }                               // because its additional sleep second
//        catch(...)                      // is irrelevant here.
//        {}
//
//        imsg << "It has. Now terminate this process" << endl;
//    }
//
//    throw 0;                            // done
//}
//
