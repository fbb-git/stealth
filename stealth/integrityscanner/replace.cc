#include "integrityscanner.ih"

void IntegrityScanner::replace(std::string &str, char const *org, 
                                        char const *replacement)
{
    size_t orglen = strlen(org);

    while (true)
    {
        string::size_type idx = str.find(org);

        if (idx == string::npos)
            break;

        str.replace(idx, orglen, replacement);
    }
}
