#include "scanner.ih"

//  SEE ALSO THE MEMBER waitForSentinel()

void Scanner::copy(Process &src, string const &fname)
{
    ofstream currentReport(fname.c_str());

    if (!currentReport)
        d_reporter.error() << "Can't open `" << fname << "' to write" << endl;

    imsg << "Scanner::copy(): about to read child input" << endl;

    string s;
    off_t length = 0;
    while (getline(src, s))
    {
        if (!checkSize(fname, length += s.length() + 1))
            return;

        imsg << "copy SAW: `" << s << '\'' << endl;

        if (s.find(d_sentinel) == 0)
        {
            imsg << "GOT Sentinel" << endl;
            break;
        }

        if (not (this->*d_skip)(s))
            currentReport << s << '\n';
    }
    testExitValue(src.str(), s);
}





