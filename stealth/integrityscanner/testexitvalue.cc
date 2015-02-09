#include "integrityscanner.ih"

void IntegrityScanner::testExitValue(std::string const &cmd, 
                            std::string const &exitStr)
{
    if (not (s_exitValue << exitStr))
        d_fatal << "No exit value for\n" <<
            cmd << "\n"
            "NOTE: this is the literal text of the executed command. "
                            "Maybe a typo?" << leave;

    if (d_testExitValue && stoul(s_exitValue[1]) != 0)
        d_fatal << 
            d_options.basename() << 
                                " terminated: non-zero exit value for\n" <<
            *d_cmdIterator << " (" << exitStr << ")" << leave;
}


