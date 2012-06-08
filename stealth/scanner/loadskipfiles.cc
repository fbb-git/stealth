#include "scanner.ih"

void Scanner::loadSkipFiles()
{
    d_skipFiles.clear();

    string name;
    if (d_arg.option(&name, 's'))       // skip files
        setSkip(name);
    else                                // or don't skip
        d_skip = &Scanner::dontSkip;

    imsg << "Scanner::loadSkipFiles(): " << d_skipFiles.size() << 
                                                        "lines" << endl;
}








