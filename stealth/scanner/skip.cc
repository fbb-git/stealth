#include "scanner.ih"

bool Scanner::skip(string const &line)
{
    auto end = d_skipFiles.end();
    return find_if(
                d_skipFiles.begin(), end, 
                [&](string const &targetLine)
                {
                    size_t idx = line.rfind(targetLine);
                    return idx + targetLine.length() == line.length();
                }
            )
            != end;
}





