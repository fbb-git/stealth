#include "scanner.ih"

bool Scanner::skip(string &line)
{
    auto end = d_skipFiles.end();

    return 
        end != find_if(
                    d_skipFiles.begin(), end, 
                    [&](string const &skip)         // skip: entry to skip
                    {
                        return skipDecision(line, skip);
                    }
                );
}





