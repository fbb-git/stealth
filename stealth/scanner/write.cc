#include "scanner.ih"

//  SEE ALSO THE MEMBER waitForSentinel()

void Scanner::write(string const &fname)
{
    ifstream source(fname.c_str());

    if (!source)
        d_reporter.error() << "Can't open `" << fname << "' to read\n";

    msg() << "Scanner::write(): about to read local `" << fname << '\'' << 
                                                                        info;
    while (true)
    {
        size_t const SIZEOF_BUF = 1000;
        char buffer[SIZEOF_BUF];

        size_t nRead = source.read(buffer, SIZEOF_BUF).gcount();

        if (!nRead)
            break;

        if (!d_sshFork.write(buffer, nRead))
            d_reporter.error() << "PUT failed.\n";
    }

    d_sshFork.flush();
}


