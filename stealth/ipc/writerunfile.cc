#include "ipc.ih"

    // runs in the foreground
void IPC::writeRunFile(pid_t pid)
{
    string const &runFileName = d_options.runFile();

    ofstream runFile(runFileName);

    m2 << "run file: " << runFileName << '\n';

    if (not (runFile << pid << endl))
    {
        kill(SIGTERM, pid);
        fmsg << "could not write " << runFileName << endl;
    }
}
