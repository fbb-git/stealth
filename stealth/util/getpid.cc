#include "util.h2"

unsigned Util::getPid(string const &runFilename)
{
    char const *runfile = runFilename.c_str();

    ifstream in(runfile);
    pid_t pid;

    if (!in || !(in >> pid))
        exit(1, "Can't read `%s'", runfile);

    in.close();

    if (kill(pid, SIGUSR1) != 0)
    {
        unlink(runfile);
        exit(1, "Removing stale run-file `%s'", runfile);
    }

    return pid;
}

    
