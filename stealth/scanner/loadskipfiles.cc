#include "scanner.ih"

void Scanner::loadSkipFiles()
{
    d_skipFiles.clear();

    if (d_skipFilePath.length())        // skip files
        setSkip();
    else                                // or don't skip
        d_skip = &Scanner::dontSkip;

    imsg << "Scanner::loadSkipFiles(): " << d_skipFiles.size() << 
                                                        "lines" << endl;
}








