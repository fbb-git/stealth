#include "integrityscanner.ih"

void IntegrityScanner::testExitValue(std::string const &cmd, 
                            std::string const &exitStr)
{
    if (not (s_exitValue << exitStr))
        fmsg << "No exit value for\n" <<
            cmd << "\n"
            "ADVICE: this is the literal text of the executed command. "
                                                     "Maybe a typo?" << noidl;

    if (d_testExitValue && stoul(s_exitValue[1]) != 0)
        fmsg << d_options.basename() << 
                                " terminated: non-zero exit value for\n" <<
                *d_cmdIterator << " (" << exitStr << ")" << noidl;
}


