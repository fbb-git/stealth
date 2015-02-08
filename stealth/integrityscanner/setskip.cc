#include "integrityscanner.ih"

void IntegrityScanner::setSkip()
try
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
catch (...)
{
    imsg << "Cannot read skip-file `" << d_skipFile << 
                                                    "': terminating" << endl;
    d_run = false;
}





