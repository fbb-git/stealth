#include "scanner.ih"

string Scanner::putCommand(string const &source, 
                             string const &destination) const
{
    struct stat statbuf;

    if (stat(source.c_str(), &statbuf))
        d_reporter.exit() << "PUT " << source << ": can't stat it" << endl;

    ostringstream command;

    command << d_sorter["DD"] << " of=" << destination << 
                                " bs=1 count=" << statbuf.st_size;

    return command.str();
}








