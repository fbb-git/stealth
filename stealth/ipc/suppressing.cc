//#include "ipc.ih"
//
//void IPC::suppressing(size_t pid)
//{
//    m2 << "Suppressing process " << pid << endl;
//
//    sleep();                        // Prepare to go to sleep, by setting
//                                    // s_selector
//
//    Lock::unlockRunFile();      // Remove the lock, allow the
//                                // suppressed process to continue
//                                // The suppressed process will wait 
//                                // for a second allowing this process
//                                // to start its waiting cycle.
//    m2 << "Waiting for the suppressed process to finish its task" << 
//                                                                    endl;
//
//    try                             // see wait() for the try {...
//    {
//        d_selector.wait();          // no need to use wait() here, 
//    }                               // because its additional sleep second
//    catch(...)                      // is irrelevant here.
//    {}
//
//    m2 << "It has. Now terminate this process" << endl;
//}
//
//
//
//
