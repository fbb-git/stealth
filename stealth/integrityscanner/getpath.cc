#include "integrityscanner.ih"

string IntegrityScanner::getPath(string const &orgLine) const
{
    size_t pathPos =
        d_pathOffset == numeric_limits<size_t>::max() ?    
            orgLine.find_first_of('/')  

        : d_pathOffset < orgLine.length() ?
            d_pathOffset 
        : 
            string::npos;

    string path;

    if (pathPos != string::npos)
        path = String::trim(orgLine.substr(pathPos));

    
    return path;
}
