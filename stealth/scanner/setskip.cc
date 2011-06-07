#include "scanner.ih"

void Scanner::setSkip(string const &fname)
{
    ifstream in;
    Errno::open(in, fname);

    for_each(istream_iterator<Line>(in), istream_iterator<Line>(), 
            FnWrap::unary(add, d_skipFiles));

    d_skip = &Scanner::skip;
}





