#include "scanner.ih"

//  SEE ALSO THE MEMBER copy()

void Scanner::waitForSentinel(istream &extractor)
{
    string  s;

    while (getline(extractor, s))
    {
        Util::debug() << "Read line `" << s << "'\n";

        if (s.find(d_sentinel) == 0)
        {
            Util::debug() << "GOT Sentinel\n";
            break;
        }
    }

    testExitValue(s);
}
