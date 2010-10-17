#include "scanner.ih"

namespace {

    bool skipTarget(string targetLine, string outputLine)
    {
        size_t idx = outputLine.rfind(targetLine);
        return idx + targetLine.length() == outputLine.length();
    }
}

bool Scanner::skip(string const &line)
{
    auto end = d_skipFiles.end();
    return find_if(d_skipFiles.begin(), end, 
                   FnWrap::unary(skipTarget, line)) != end;
}





