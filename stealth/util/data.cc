#include "util.h2"

bool     Util::s_keepAlive = false;
bool     Util::s_debug = false;
unsigned Util::s_repeatInterval = 0;
unsigned Util::s_delayInterval = 0;
Selector Util::s_selector;
string   Util::s_runFilename;
FILE    *Util::s_runFILE = 0;
bool     Util::s_mainProcess = false;
