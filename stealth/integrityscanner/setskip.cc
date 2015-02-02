#include "integrityscanner.ih"

void IntegrityScanner::setSkip()
{
    ifstream in;
    Exception::open(in, d_skipFile);

    for_each(
        istream_iterator<StringLine>(in), istream_iterator<StringLine>(), 
        [&](std::string const &line)
        {
            add(line, d_skipFiles);
        }
    );

    d_skip = &IntegrityScanner::skip;
}





