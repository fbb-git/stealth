#include "scanner.h2"

void Scanner::testExitValue(std::string const &s)
{
    if (d_testExitValue && s.substr(s.find_last_not_of(" ")) != "0")
    {
        d_reporter << endl <<
            endl <<
            "Program terminated due to non-zero exit value for " << endl <<
            *d_cmdIterator << endl;

        Util::exit(1, "Non-zero exit value for `%s'", s.c_str());
    }
}


