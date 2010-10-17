#include "scanner.ih"

//  SEE ALSO THE MEMBER waitForSentinel()

void Scanner::copy(std::istream &src, string const &fname)
{
    ofstream currentReport(fname.c_str());

    if (!currentReport)
        d_reporter.error() << "Can't open `" << fname << "' to write" << endl;

    msg() << "Scanner::copy(): about to read child input" << info;

    string s;
    off_t length = 0;
    while (getline(src, s))
    {
        if (!checkSize(fname, length += s.length() + 1))
            return;

        msg() << "copy SAW: `" << s << '\'' << info;

        if (s.find(d_sentinel) == 0)
        {
            msg() << "GOT Sentinel" << info;
            break;
        }

        if (not (this->*d_skip)(s))
            currentReport << s << "\n";
    }
    testExitValue(s);
}





