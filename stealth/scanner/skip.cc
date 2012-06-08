#include "scanner.ih"

// line: a line like 
//  9fd210eed1190870f69c9bc7544cfacb82099efd  /root/aantekeningen
//
// toSkip: a line from the `skipfiles' file
//  Files are skipped if:
//      1. the filename in `line' equals toSkip: equal filenames
//      2. the filename in `line' begins with toSkip and toSkip and
//         toSkip ends in /: toSkip is a directory, and line is an 
//                               entry in that directory

bool Scanner::skip(string line)
{
    line.erase(0, line.find('/'));    // keep the filename

    auto end = d_skipFiles.end();
    return find_if(
                d_skipFiles.begin(), end, 
                [&](string const &toSkip)   // toSkip: line to skip
                {
                    if (line == toSkip)     // line contains toSkip
                        return true;        // skip this file

                    if (toSkip.back() != '/')   // toSkip isn't a dir.:
                        return false;           // don't skip this entry

                      // skip this entry if line contains toSkip at idx
                    return line.find(toSkip) == 0;
                }
            )
            != end;
}





