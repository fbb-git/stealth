#include "integrityscanner.ih"

string IntegrityScanner::putCommand(string const &source, 
                             string const &destination) const
{
    struct stat statbuf;

    if (stat(source.c_str(), &statbuf))
        fmsg << "PUT " << source << ": can't stat it" << endl;

    ostringstream command;

    command << d_policyFile["DD"] << " of=" << destination << 
                                " bs=1 count=" << statbuf.st_size;

    return command.str();
}








