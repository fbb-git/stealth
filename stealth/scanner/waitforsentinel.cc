#include "scanner.ih"

//  SEE ALSO THE MEMBER copy()

void Scanner::waitForSentinel(istream &extractor)
{
    string  s;

    while (getline(extractor, s))
    {
        imsg << "Read line `" << s << '\'' << endl;

        if (s.find(d_sentinel) == 0)
        {
            imsg << "GOT Sentinel" << endl;
            break;
        }
    }

    testExitValue(s);
}
