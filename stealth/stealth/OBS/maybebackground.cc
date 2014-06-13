//#include "stealth.ih"
//
//void Stealth::maybeBackground()
//{
//    if (not d_options.keepAlive())
//        return;
//
//    ofstream runFile;
//    Exception::open(runFile, Lock::runFilename());
//
//    int pid = fork();
//    if (pid < 0)
//        fmsg << "--keep-alive failed due to failing fork() system call." <<
//                                                                        endl;
//
//    if (pid > 0)        // parent process (gets child pid)
//    {
//        runFile << pid << '\n';
//        throw 0;
//    }
//
//    s_mainProcess = true;
//}


