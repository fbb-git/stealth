#include "scanner.ih"

//  SEE ALSO THE MEMBER waitForSentinel()

void Scanner::copy(std::istream &src, string const &fname)
{
    ofstream currentReport(fname.c_str());

    if (!currentReport)
        d_reporter.exit() << "Can't open `" << fname << "' to write" << endl;

    string s;
    off_t length = 0;

    Util::debug() << "Scanner::copy(): about to read child input " << endl;

    while (getline(src, s))
    {
        if (!checkSize(fname, length += s.length() + 1))
            return;

        Util::debug() << "copy SAW: `" << s << "'" << endl;

        if (s.find(d_sentinel) == 0)
        {
            Util::debug() << "GOT Sentinel" << endl;
            break;
        }
        currentReport << s << endl;
    }
    testExitValue(s);
}





