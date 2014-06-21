#include "integrityscanner.ih"

void IntegrityScanner::loadSkipFiles()
{
    d_skipFilePath = d_options.skipFilePath();

    if (d_skipFilePath.length())        // skip files
        setSkip();
    else                                // or don't skip
        d_skip = &IntegrityScanner::dontSkip;

    m3 << "loadSkipFiles: " << d_skipFiles.size() << " lines" << endl;
}








