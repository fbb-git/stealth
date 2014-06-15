#include "integrityscanner.ih"

string IntegrityScanner::putCommand(string const &source, 
                             string const &destination) const
{
    struct stat statbuf;

    if (stat(source.c_str(), &statbuf))
        d_stealthLog << "PUT " << source << ": can't stat it" << StealthEnums::leave;

    ostringstream command;

    command << d_policyFile["DD"] << " of=" << destination << 
                                " bs=1 count=" << statbuf.st_size;

    return command.str();
}








