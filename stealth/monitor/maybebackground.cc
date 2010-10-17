#include "monitor.ih"

void Monitor::maybeBackground()
{
    if (keepAlive())
    {
        ofstream out;
        Msg::open(out, Lock::runFilename());

        int pid = fork();
        if (pid < 0)
            msg() << "--keepalive failed due to failing fork() system "
                                                            "call." << fatal;

        if (pid > 0)        // parent process (gets child pid)
        {
            out << pid << "\n";
            throw 0;
        }

        s_mainProcess = true;
    }
}


