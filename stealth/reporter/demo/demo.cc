/*
                              demo.cc

   $Id$

   $Log$
   Revision 1.2  2003/06/20 18:58:14  frank
   Changes are recorded in stealth/debian/changelog

*/

#include "demo.h"


int main(int argc, char **argv, char **envp)
{
    try
    {
        Reporter &rep = Reporter::get("report");

        rep << Util::date << ": Hello world\n";
    
        rep.reset();
    
        string s;
    
        while (getline(rep, s))
            cout << "Added: " << s << endl;
    
        return 0;
    }
    catch(Reporter::Exception e)
    {
        cerr << "Exception " << e << endl;
        return 1;
    }
}
