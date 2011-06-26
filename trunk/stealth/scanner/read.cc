#include "scanner.ih"

//  SEE ALSO THE MEMBER waitForSentinel()

void Scanner::read(std::istream &src, string const &fname)
{
    ofstream target(fname.c_str());

    if (!target)
        d_reporter.error() << "Can't open `" << fname << "' to write" << endl;

    imsg << "Scanner::read(): about to read child input" << endl;

    char c;
    string partialSentinel;

    size_t length = 0;
    off_t size = 0;

    while (true)
    {
        if (!src.read(&c, 1))               // read char by char
        {
            d_quit = true;
            d_reporter.error() << "Incomplete read from `" << fname << "'" <<
                                                                        endl;
            return;
        }

        if (!checkSize(fname, ++size))
            return;

        if (c == d_sentinel[length])       // got next sentinel char
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
    testExitValue(partialSentinel);
}


