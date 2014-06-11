#include "ipc.ih"

void IPC::suppress(size_t pid)
{
    ofstream runFile;
    Exception::open(runFile, Lock::runFilename());  // rewrite the runfile

    runFile << pid << '\n' <<
               getpid() << '\n';// add this process's id to the runfile

    runFile.close();            // done. The runfile now contains the
                                // signalled process ID and the current
                                // process ID 

                                // install the reply handler.
    Signal::instance().add(SIGUSR1, *this);
}





