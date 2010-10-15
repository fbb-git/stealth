#include "scanner.ih"

namespace {

    bool skip(string targetLine, string outputLine)
    {
        size_t idx = outputLine.rfind(targetLine);
        return idx + targetLine.length() == outputLine.length();
    }
}

bool Scanner::testAccept(string const &line)
{
    auto end = d_skipFiles.end();
    return find_if(d_skipFiles.begin(), end, 
                   FnWrap::unary(skip, line)) == end;
}





