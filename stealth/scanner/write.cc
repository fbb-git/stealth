#include "scanner.h2"

//  SEE ALSO THE MEMBER waitForSentinel()

void Scanner::write(string const &fname)
{
    ifstream source(fname.c_str());

    if (!source)
        Util::exit(1, "Can't open `%s' to read", fname.c_str());

    dout("Scanner::write(): about to read local `" << fname << "'");

    while (true)
    {
        unsigned const SIZEOF_BUF = 1000;
        char buffer[SIZEOF_BUF];

        unsigned nRead = source.read(buffer, SIZEOF_BUF).gcount();

        if (!nRead)
            break;

        if (!d_sshFork.out().write(buffer, nRead))
            Util::exit(1, "PUT failed.");
    }

    d_sshFork.out().flush();
}


