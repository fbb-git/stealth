#include "util.h2"

void Util::showVersion()
{ 
    cerr << Arg::getInstance().basename() << " version " << version << 
            " (Frank B. Brokken, f.b.brokken@rc.rug.nl, " << year << ")\n";
    ::exit(1);
}

