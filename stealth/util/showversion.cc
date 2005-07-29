#include "util.h2"

void Util::showVersion()
{ 
    cerr << Arg::getInstance().basename() << " version " << version << 
            " (Frank B. Brokken, f.b.brokken@rug.nl, " << year << ")\n";
    throw ERROR; // ::exit(1);
}

