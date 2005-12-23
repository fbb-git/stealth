#include "util.ih"

void Util::showVersion()
{ 
    cerr << Arg::instance().basename() << " version " << version << 
            " (Frank B. Brokken, f.b.brokken@rug.nl, " << year << ")\n";
    throw ERROR; // ::exit(1);
}

