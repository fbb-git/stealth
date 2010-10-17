#include "scanner.ih"

void Scanner::setSkip(string const &fname)
{
    ifstream in;
    Msg::open(in, fname);

    ::copy(istream_iterator<Line>(in), istream_iterator<Line>(), 
            back_inserter(d_skipFiles));

    d_skip = &Scanner::skip;
}





