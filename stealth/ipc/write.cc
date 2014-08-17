#include "ipc.ih"

void IPC::write(char const *request) const
{
    fstream runFile(d_options.runFile(), ios::in | ios::out);

    runFile.ignore(numeric_limits<int>::max(), '\n');   // skip one line
    runFile.seekp(0, ios::cur);                         // prepare for writing
    runFile << request << '\n';                         // write the request
    runFile.close();                                    // done.
}
