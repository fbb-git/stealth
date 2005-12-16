#include "iofork.ih"

void IOFork::childProcess()
{
    vector<string>  vs;
    char const **argv;

    argv = split(vs);                                   // split commandline

    if (Arg::getInstance().option('d'))
        for (char const **it = argv; *it; it++)
            cerr << "childProcess arg: " << *it << endl;

    int stdErr = open("/dev/null", O_WRONLY);           // ignore stdError

    if (stdErr == -1)
        Util::exit("Can't open /dev/null");

    dup2(stdErr, STDERR_FILENO);
    close(stdErr);                                      // stdError ignored


    execv(argv[0], const_cast<char **>(argv));          // call the child
    exit(1);
}




