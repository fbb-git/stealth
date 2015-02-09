#include "integrityscanner.ih"

void IntegrityScanner::setSkip()
{
    ifstream in(d_skipFile);
    if (not in)
        d_fatal << "cannot read skip-file `" << d_skipFile << '\'' << leave;

    for_each(
        istream_iterator<StringLine>(in), istream_iterator<StringLine>(), 
        [&](std::string const &line)
        {
            add(line, d_skipFiles);
        }
    );

    d_skip = &IntegrityScanner::skip;
}






