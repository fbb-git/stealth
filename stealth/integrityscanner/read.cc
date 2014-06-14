#include "integrityscanner.ih"

//  SEE ALSO THE MEMBER waitForSentinel()

void IntegrityScanner::read(Process &src, string const &fname)
{
    ofstream target(fname.c_str());

    if (!target)
        d_log << "Can't open `" << fname << "' to write" << ModeEnum::leave;

    imsg << "IntegrityScanner::read(): about to read child input" << endl;

    char c;
    string partialSentinel;

    size_t length = 0;
    off_t size = 0;

    while (true)
    {
        if (!src.read(&c, 1))               // read char by char
        {
            d_run.setMode(RunMode::TERMINATE);
            d_log << "Incomplete read from `" << fname << "'" <<
                                                            ModeEnum::leave; 
            return;
        }

        checkSize(fname, ++size);           // throws if not OK

        if (c == d_sentinel[length])        // got next sentinel char
        {
            length++;
                                            // matched the sentinel
            if (length == d_sentinel.length())
            {
                imsg << "GOT Sentinel" << endl;

                string tail;                    // get the end-chars as well
                getline(src, tail);
                partialSentinel += tail;

                break;                          // so we're done.
            }
            partialSentinel += c;       // append c to the partial Sentinel
        }
        else
        {
            if (length)
            {
                target.write(partialSentinel.c_str(), length);
                partialSentinel.erase();
                length = 0;
            }
            target.write(&c, 1);
        }
    }
    testExitValue(src.str(), partialSentinel);
}
