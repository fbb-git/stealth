//#include "stealth.ih"
//
//// Called by stealth --lock ...
////
//void Stealth::lock()
//{
//    size_t pid = getPid(runfile);
//    if (pid == 0)
//        throw 1;
//
//    imsg << "Trying to lock " << runfile << " of process " << pid << endl;
//
//    Lock::setRunFilename(runfile);
//    Lock::lockRunFile(Lock::BLOCKING);      // Obtain the lock on the runfile
//}
//
