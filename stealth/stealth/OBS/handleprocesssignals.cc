//#include "stealth.ih"
//
//// activated by 
//void Stealth::handleProcessSignals(int signum)
//{
//    switch (signum)
//    {
//        case SIGTERM:                       // TERMINATE
//            if (s_mode != TERMINATED)
//            {
//                s_quit = true;
//                s_mode = TERMINATE;
//            }
//        break;
//
//        case SIGHUP:                        // RERUN
//            if (s_mode != KEEP_ALIVE)       // wakeup if mode is KEEP_ALIVE
//                return;
//        break;
//
//        case SIGUSR1:                       // SUSPEND
//            if (s_mode == KEEP_ALIVE)
//                s_mode = SUSPEND;          // changed to SUSPENDED in
//                                            // processMode() 
//        break;
//
//        case SIGUSR2:                       // RESUME
//            if (s_mode == SUSPEND || s_mode == SUSPENDED)
//                s_mode = KEEP_ALIVE;
//        break;
//
//        case SIGPIPE:                       // RELOAD: changes KEEP_ALIVE
//            if (s_mode == KEEP_ALIVE)       // temporarily into RELOAD
//                s_mode = RELOAD;            // for processMode() to handle.
//        break;
//
//        default:
//        return;
//    }
//
//    wakeup();
//    signal(signum, handleProcessSignals);
//}

