#include "integrityscanner.ih"

//  SEE ALSO THE MEMBER copy()

void IntegrityScanner::waitForSentinel(Process &extractor)
{
    string line;

    while (getline(extractor, line))
    {
        m3 << "read line `" << line << '\'' << endl;

        if (line.find(d_sentinel) == 0)
        {
            m3 << "GOT Sentinel" << endl;
            break;
        }
    }

    testExitValue(extractor.str(), line);
}
