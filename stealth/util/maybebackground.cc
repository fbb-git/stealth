#include "util.h2"

void Util::maybeBackground()
{
    if (keepAlive())
    {
        int pid = fork();
        if (pid < 0)
            exit(1, "--keepalive / --rerun failed due to failing "
                            "fork() system call.");

        if (pid > 0)        // parent process gets child pid
        {
            cout << "Stealth: pid = " << pid << endl;
            ::exit(0);
        }

        signal(SIGHUP, Util::handleRerun);
        signal(SIGTERM, Util::handleTerminate);
    }
}


