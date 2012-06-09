#include "scanner.ih"

//  SEE ALSO THE MEMBER waitForSentinel()

void Scanner::copy(Process &src, string const &fname)
{
    ofstream currentReport(fname.c_str());

    if (!currentReport)
        d_reporter.error() << "Can't open `" << fname << "' to write" << endl;

    imsg << "Scanner::copy(): about to read child input" << endl;

    string line;
    off_t length = 0;
    while (getline(src, line))
    {
        if (!checkSize(fname, length += line.length() + 1))
            return;

        imsg << "copy SAW: `" << line << '\'' << endl;

        if (line.find(d_sentinel) == 0)
        {
            imsg << "GOT Sentinel" << endl;
            break;
        }

        s_split << line;                    // get the last word on this line
        string last = s_split[1];

        if (not (this->*d_skip)(last))
            currentReport << line << '\n';
    }
    testExitValue(src.str(), line);
}





