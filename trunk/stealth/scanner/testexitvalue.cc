#include "scanner.ih"

void Scanner::testExitValue(std::string const &s)
{
    if (d_testExitValue && s.substr(s.find_last_not_of(" ")) != "0")
        d_reporter.error() << 
            "Program terminated due to non-zero exit value for\n" <<
            *d_cmdIterator << " (" << s << ")" << endl;
}


