#include "scanner.ih"

//  SEE ALSO THE MEMBER copy()

void Scanner::waitForSentinel(istream &extractor)
{
    string  s;

    while (getline(extractor, s))
    {
        msg() << "Read line `" << s << '\'' << info;

        if (s.find(d_sentinel) == 0)
        {
            msg() << "GOT Sentinel" << info;
            break;
        }
    }

    testExitValue(s);
}
