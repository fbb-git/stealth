#include "ipc.ih"

void IPC::write(string const &msg) const
{
    fstream runFile(d_options.runFile(), ios::in | ios::out);

    runFile.ignore(numeric_limits<int>::max(), '\n');   // skip one line
    runFile.seekp(0, ios::cur);                         // prepare for writing
    runFile << msg << '\n' <<                           // write the msg
                getpid() << '\n';                       // write our own pid
    runFile.close();                                    // done.
}
