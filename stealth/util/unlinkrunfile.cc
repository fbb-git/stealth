#include "util.h2"

void Util::unlinkRunfile()
{
    unlink(s_runFilename.c_str());  // s_runFilename may be empty 
}

    
