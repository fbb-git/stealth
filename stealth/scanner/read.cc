#include "scanner.h2"

//  SEE ALSO THE MEMBER waitForSentinel()

void Scanner::read(std::istream &src, string const &fname)
{
    ofstream target(fname.c_str());

    if (!target)
        Util::exit(1, "Can't open `%s' to write", fname.c_str());

    dout("Scanner::read(): about to read child input ");

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
                dout("GOT Sentinel");

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


