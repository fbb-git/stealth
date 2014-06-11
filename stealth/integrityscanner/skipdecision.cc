#include "integrityscanner.ih"

// line: lines like
//  < 9fd210eed1190870f69c9bc7544cfacb82099efd  /root/aantekeningen
// so:
//  /root/aantekeningen
// toSkip: a line from the `skipfiles' file
//  Files are skipped if 'line' contains `toSkip' and:
//      1. toSkip ends in '/'
//  or
//      2. the line ends after 'toSkip' or after 'toSkip' 
//  or
//      3. the character on 'line' after 'toSkip' is a blank space


bool IntegrityScanner::skipDecision(string &path, string const &skipPath) const
{
    if (path.find(skipPath) != 0)   // skipPath not in path
        return false;

    if 
    (                               // SKIP this entry, IF:
        skipPath.back() == '/'      //  skipPath ends in '/'
        ||                          // or
        path == skipPath            //  path equals skipPath
    )   
    {
        path = skipPath;            // replace path by skipPath
        return true;
    }

    return false;                   // else don't skip this entry
}

