#include "integrityscanner.ih"

void IntegrityScanner::loadSkipFiles()
{
    d_skipFile = d_options.skipFile();

    if (d_skipFile.length())        // skip files
        setSkip();
    else                                // or don't skip
        d_skip = &IntegrityScanner::dontSkip;

    m3 << "loadSkipFiles: " << d_skipFiles.size() << " lines" << endl;
}








