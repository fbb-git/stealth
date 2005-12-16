#include "scanner.ih"

//  SEE ALSO THE MEMBER waitForSentinel()

void Scanner::read(std::istream &src, string const &fname)
{
    ofstream target(fname.c_str());

    if (!target)
        d_reporter.exit() << "Can't open `" << fname << "' to write" << endl;

    Util::debug() << "Scanner::read(): about to read child input" << endl;

    char c;
    string partialSentinel;

    unsigned length = 0;
    while (true)
    {
        src.read(&c, 1);                    // read char by char

        if (c == d_sentinel[length])       // got next sentinel char
        {
            length++;

            if (length == d_sentinel.length())  // matched the sentinel
            {
                Util::debug() << "GOT Sentinel" << endl;

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


