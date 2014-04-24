#include "scanner.ih"

void Scanner::setSkip()
{
    ifstream in;
    Exception::open(in, d_skipFilePath);

    for_each(
        istream_iterator<StringLine>(in), istream_iterator<StringLine>(), 
        [&](std::string const &line)
        {
            add(line, d_skipFiles);
        }
    );

    d_skip = &Scanner::skip;
}





