#include "scanner.ih"

// line: a line like 
//  9fd210eed1190870f69c9bc7544cfacb82099efd  /root/aantekeningen
//
// targetLine: a line from the `skipfiles' file

bool Scanner::skip(string const &line)
{
    auto end = d_skipFiles.end();
    return find_if(
                d_skipFiles.begin(), end, 
                [&](string const &targetLine)   // tartline: line to skip
                {
                    size_t idx = line.find('/');    // find the 1st /

                      // skip this entry if line contains targetline at idx
                    return line.find(targetLine, idx) == idx;
                }
            )
            != end;
}





