//                              demo.h

#ifndef _H_demo_
#define _H_demo_

/*
   $Id$

   $Log$
   Revision 1.3  2003/11/30 14:21:29  frank
   Adding facilities to reuse the Reporter: reinit() re-initializes the reporter
   but note that reset() must still be used. See demo/demo.cc for an example

   Revision 1.2  2003/06/20 18:58:14  frank
   Changes are recorded in stealth/debian/changelog

*/

//#include <iosfwd>
#include <iostream>
//#include <fstream>
#include <string>
//#include <sstream>

#include "../reporter.h"
#include "../../util/util.h"
#include "../../errno/errno.h"

using namespace FBB;
using namespace std;

#endif
