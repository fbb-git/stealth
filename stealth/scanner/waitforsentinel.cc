#include "scanner.h2"

//  SEE ALSO THE MEMBER copy()

void Scanner::waitForSentinel(istream &extractor)
{
    string  s;

    while (getline(extractor, s))
    {
        dout("Read line `" << s << "'");
        if (s.find(d_sentinel) == 0)
        {
            dout("GOT Sentinel");
            break;
        }
    }

    testExitValue(s);
}
