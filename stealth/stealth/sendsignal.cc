//#include "stealth.ih"
//
//void Stealth::sendSignal(int signum, char const *signame, pid_t pid)
//{
//    if (kill(pid, signum))          
//    {                               
//        Lock::unlinkRunFile();
//
//        fmsg << "Can't send " << signame << " to process `" << pid << "',\n"  
//                 "removed stale run-file `" << Lock::runFilename << '.' << 
//                                                                        endl;
//    }
//
//    imsg << signame << " sent" << endl;
//}

