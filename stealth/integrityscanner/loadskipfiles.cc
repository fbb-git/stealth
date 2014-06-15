#include "integrityscanner.ih"

void IntegrityScanner::loadSkipFiles()
{
    d_skipFiles.clear();

    if (d_skipFilePath.length())        // skip files
        setSkip();
    else                                // or don't skip
        d_skip = &IntegrityScanner::dontSkip;

    m4 << "loadSkipFiles: " << d_skipFiles.size() << " lines" << endl;
}








