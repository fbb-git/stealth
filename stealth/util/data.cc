#include "util.h2"

bool     Util::s_keepAlive = false;
unsigned Util::s_repeatInterval = 0;
unsigned Util::s_delayInterval = 0;
Selector Util::s_selector;
string   Util::s_runFilename;