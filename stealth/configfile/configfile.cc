#include "configfile.h2"

ConfigFile::ConfigFile(char const *name, bool keepComment, bool ignoreCase)
:
    d_keepComment(keepComment),
    d_ignoreCase(ignoreCase),
    d_status(true)
{
    ifstream stream(name);

    if (!stream)
    {
        d_status = false;
        return;
    }

    string line;

    while (nextLine(stream, line))
    {
        if (line.length())
            d_lines.push_back(line);
    }
}

