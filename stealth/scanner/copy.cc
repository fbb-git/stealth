#include "scanner.h2"

//  SEE ALSO THE MEMBER waitForSentinel()

void Scanner::copy(std::istream &src, string const &fname)
{
    ofstream currentReport(fname.c_str());

    if (!currentReport)
        Util::exit(1, "Can't open `%s' to write", fname.c_str());

    string s;

    dout("Scanner::copy(): about to read child input ");
    while (getline(src, s))
    {
        dout("copy SAW: `" << s << "'");

        if (s.find(d_sentinel) == 0)
        {
            dout("GOT Sentinel");
            break;
        }
        currentReport << s << endl;
    }

    testExitValue(s);
}
