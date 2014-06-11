#include "integrityscanner.ih"

void IntegrityScanner::add(std::string const &line, StringVector &skipFiles)
{
    string &&trimmed = String::trim(line);

    if (trimmed.empty() || *trimmed.begin() == '#') // skip empty lines and
        return;                                     // comment

    skipFiles.push_back(trimmed);
}





