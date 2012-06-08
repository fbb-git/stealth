#include "scanner.ih"

void Scanner::setSkip(string const &fname)
{
    ifstream in;
    Errno::open(in, fname);

    for_each(
        istream_iterator<StringLine>(in), istream_iterator<StringLine>(), 
        [&](std::string const &line)
        {
            add(line, d_skipFiles);
        }
    );
    
    d_skip = &Scanner::skip;
}





