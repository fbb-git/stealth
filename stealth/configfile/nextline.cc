#include "configfile.h2"

bool ConfigFile::nextLine(std::istream &istr, std::string &line)
{
    if (!getline(istr, line))           // no more lines
        return false;

    std::string::size_type              // any non-white chars ?    
        pos = line.find_first_not_of(" \t");

    if (pos == std::string::npos)       // only WS
    {
        line.erase();
        return true;                    // got a line, but it's empty
    }

    line.erase(0, pos);                 // remove initial WS

    unsigned
        lastChar = line.length() - 1;   // the last char index

    if (line[lastChar] == '\\')         // is it '\\' ?
    {
        line.erase(lastChar);           // erase it
        std::string
            append;
        if (nextLine(istr, append))     // determine the next line
            line += append;             // append the next line
    }
    
    if
    (
        d_keepComment                   // keep comment or no # ?
        ||
        (pos = line.find_first_of('#')) == std::string::npos
    )
        return true;

    line.erase(pos);                    // throw away from '#'
    return true;
}
