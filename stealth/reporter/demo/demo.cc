/*
                              demo.cc

    g++ demo.cc -L../.. -lstealth | & less
*/

#include "demo.h"

int main(int argc, char **argv, char **envp)
{
    try
    {
        Reporter rep("report");

        rep << Util::date << ": Hello world\n";
    
        rep.reset();
    
        string s;

        cout << "========= 0 ===========\n";
    
        while (getline(rep, s))
            cout << "Added: " << s << endl;

        cout << "========= 1 ===========\n";

        sleep(5);

        rep.reinit();                   // make sure we can add new info 
                                        // as a new run
    
                                        // insert info
        rep << Util::date << ": Hello world (2nd time)\n";

        rep.reset();                    // reset the stream to read it again
    
        while (getline(rep, s))
            cout << "Added: " << s << endl;

        cout << "========= 2 ===========\n";

        return 0;
    }
    catch(Errno &e)
    {
        cerr << "Exception " << e.why() << endl;
        return 1;
    }
}
