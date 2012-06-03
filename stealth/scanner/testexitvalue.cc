#include "scanner.ih"

void Scanner::testExitValue(std::string const &cmd, 
                            std::string const &exitStr)
{
    if (not (s_exitValue << exitStr))
        d_reporter.error() << "No exit value for\n" <<
            cmd << "\n"
            "NOTE: this is the literal text of the executed command. "
                            "Maybe a typo?" << endl;

    if (d_testExitValue && A2x(s_exitValue[1]) != 0)
        d_reporter.error() << 
            "Program terminated due to non-zero exit value for\n" <<
            *d_cmdIterator << " (" << exitStr << ")" << endl;

}


