#include "util.h2"

void Util::maybeBackground()
{
    if (keepAlive())
    {
        char const *runfile = s_runFilename.c_str();

        ofstream out(runfile);
        if (!out)
            exit(1, "Can't write `%s'", runfile);

        int pid = fork();
        if (pid < 0)
            exit(1, "--keepalive failed due to failing "
                            "fork() system call.");

        if (pid > 0)        // parent process gets child pid
        {
            out << pid << endl;
            ::exit(0);
        }

        atexit(unlinkRunfile);

        signal(SIGHUP, Util::handleRerun);
        signal(SIGTERM, Util::handleTerminate);
        signal(SIGUSR1, Util::handleSIGUSR1);
    }
}


