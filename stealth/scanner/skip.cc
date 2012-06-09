#include "scanner.ih"

// line: the last entry of lines like
//  9fd210eed1190870f69c9bc7544cfacb82099efd  /root/aantekeningen
// so:
//  /root/aantekeningen
//
// toSkip: a line from the `skipfiles' file
//  Files are skipped if:
//      1. the filename in `line' equals toSkip: equal filenames
//      2. the filename in `line' begins with toSkip and toSkip and
//         toSkip ends in /: toSkip is a directory, and line is an 
//                               entry in that directory

bool Scanner::skip(string &lastWord)
{
    auto end = d_skipFiles.end();
    return find_if(
                d_skipFiles.begin(), end, 
                [&](string const &toSkip)   // toSkip: entry to skip
                {
                    if (lastWord == toSkip)     // lastWord contains toSkip
                        return true;        // skip this file

                    if (toSkip.back() != '/')   // toSkip isn't a dir.:
                        return false;           // don't skip this entry

                      // skip this entry and remove the filename from
                      // 'lastWord' if lastWord contains toSkip at 0
                    if (lastWord.find(toSkip) == 0)
                    {
                        lastWord = toSkip;
                        return true;
                    }

                    return false;           // don't skip this entry
                }
            )
            != end;
}





