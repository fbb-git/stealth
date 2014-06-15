#include "integrityscanner.ih"

//  SEE ALSO THE MEMBER copy()

void IntegrityScanner::waitForSentinel(Process &extractor)
{
    string  s;

    while (getline(extractor, s))
    {
        m4 << "read line `" << s << '\'' << endl;

        if (s.find(d_sentinel) == 0)
        {
            m3 << "GOT Sentinel" << endl;
            break;
        }
    }

    testExitValue(extractor.str(), s);
}
