#include "../iofork.h"

#ifndef _SYSINC_STRING_
#include <string>
#define _SYSINC_STRING_
#endif

#ifndef _SYSINC_IOSTREAM_
#include <iostream>
#define _SYSINC_IOSTREAM_
#endif

#ifndef _INCLUDED_ARG_H_
#include "../../arg/arg.h"
#endif

using namespace FBB;
using namespace std;

int main(int argc, char **argv, char **envp)
{
    Arg("d", argc, argv);

//    IOFork sf("/usr/bin/ssh frankbash@localhost -q");
    IOFork sf("/usr/bin/diff /tmp/stealthdemo/remote/bin /tmp/stealthdemo/remote/bin.cur");

    sf.fork();

        string     line;
        unsigned int    nr = 1;

//        cout << "Next: " << flush;

//        while (getline(std::cin, line))
        {
//            cout << "Sending " << line << endl;
        
//            sf.out() << line << endl << "/bin/echo EOC" << endl;    

            while (getline(sf.in(), line) && line != "EOC")
                cout << nr++ << ": " << line << std::endl;

//            cout << "Next: " << flush;
        }

    return 0;
}


