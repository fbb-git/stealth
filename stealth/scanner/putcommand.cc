#include "scanner.h2"

string Scanner::putCommand(string const &source, 
                             string const &destination) const
{
    struct stat statbuf;

    if (stat(source.c_str(), &statbuf))
        Util::exit(1, "PUT %s: can't stat it", source.c_str());

    ostringstream command;

    command << d_sorter["DD"] << " of=" << destination << 
                                " bs=1 count=" << statbuf.st_size;

    return command.str();
}








