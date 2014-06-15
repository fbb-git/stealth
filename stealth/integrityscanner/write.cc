#include "integrityscanner.ih"

//  SEE ALSO THE MEMBER waitForSentinel()

void IntegrityScanner::write(string const &fname)
{
    ifstream source(fname.c_str());

    if (!source)
        d_stealthLog << "Can't open `" << fname << "' to read." <<
                                                        StealthEnums::leave; 

    m3 << "about to read local `" << fname << '\'' << endl;

    while (true)
    {
        size_t const SIZEOF_BUF = 1000;
        char buffer[SIZEOF_BUF];

        size_t nRead = source.read(buffer, SIZEOF_BUF).gcount();

        if (!nRead)
            break;

        if (!d_sshFork.write(buffer, nRead))
            d_stealthLog << "PUT failed." << StealthEnums::leave;
    }

    d_sshFork.flush();
}


