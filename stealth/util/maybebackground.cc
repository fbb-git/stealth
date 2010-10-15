#include "util.ih"

void Util::maybeBackground()
{
    if (keepAlive())
    {
        char const *runfile = s_runFilename.c_str();

        ofstream out(runfile);
        if (!out)
            exit("Can't write `%s'", runfile);

        int pid = fork();
        if (pid < 0)
            exit("--keepalive failed due to failing fork() system call.");

        if (pid > 0)        // parent process (gets child pid)
        {
            out << pid << "\n";
            throw OK;       // ::exit(0);
        }
        s_mainProcess = true;
    }
}


