#include "scanner.ih"

/*
    Example of diff-output:

33c33
< 90d8b506d249634c4ff80b9018644567  out
---
> b88d0b77db74cc4a742d7bc26cdd2a1e  out

*/

bool Scanner::noDifferences(std::string const &current,
                                  std::string const &logfile)
{
    imsg << "Scanner::noDifferences(): started " << 
            d_sorter["DIFF"] << " " << current << " " << logfile << endl;

    d_shFork << d_sorter["DIFF"] << " " << current << " " << logfile <<
                                                                     '\n' <<
                        "/bin/echo \"" << d_sentinel << "\"" << endl;

    HashString<pair<string, vector<string>>> status;

    imsg << "Scanner::noDifferences():         /bin/echo " << d_sentinel << 
                                                                        endl;

    //  key is string, case sensitive.
    //
    //  The last element of the lines produced by diff is used as the
    //  key. For the current function to operate sensibly, this should be
    //  a filename or path/file.
    //
    //  If the first character of the line is a < or >, then a modification is
    //  detected: for these lines the following happens:
    //      1. If the key already existed its .first element is set to
    //          "modified". If the key didn't exist yet, it is set to
    //          "added" at at '<'. It is set to "skipping" at a '>' if the
    //          pathname is found in the array of files to skip. Otherwise
    //          it's set to "removed".
    //      2. The line itself is pushed back to the .second (vector) element
    //          of the pair.
    //
    //  At the end, if the hashtable has any elements, the table is inserted
    //  into the d_reporter and `false' is returned. If the hashtable contains
    //  no elements, 'true' is returned.

    string  s;

    imsg << "Scanner::noDifferences(): starting to read lines" << endl;

    while (getline(d_shFork, s))
    {
        imsg << "Scanner::noDifferences():      got: `" << s << "'\n" 
            "Scanner::noDifferences(): sentinel: `" << d_sentinel << '\'' <<
                                                                        endl;
        if (s == d_sentinel)
            break;

        if (!(s_split << s))
            continue;                       // no match at empty lines ?

        string key = s_split[1];            // get the key
        bool exists = status.count(key);

        if (s[0] == '<')
                status[key].first = exists ? "MODIFIED" : "ADDED";
        else if (s[0] == '>')   // removal or skip, e.g.,   > b88d0b....  out
        {
            if ((this->*d_skip)(key))
                status[key].first = "SKIPPING";
            else
                status[key].first = exists ? "MODIFIED" : "REMOVED";
        }
        else
            continue;

        status[key].second.push_back(s);
    }

    if (!status.size())                 // no elements ?
    {
        imsg << "no differences were observed" << endl;

        rename(current.c_str(), logfile.c_str());   // install `logfile'
        return true;                   // nothing to report
    }

    if (d_label.length())
        d_reporter << d_label << endl;

    for
    (
        HashString< pair<string, vector<string> > >::iterator
        begin = status.begin(), end = status.end();
            begin != end;
                begin++
    )
    {
        d_reporter << begin->second.first  << ": " << begin->first << endl;

        for
        (
            vector<string>::iterator
                sbegin = begin->second.second.begin(),
                send = begin->second.second.end();
                    sbegin != send;
                        sbegin++
        )
            d_reporter << "    " << *sbegin << endl;
    }

    string logFilename = logfile + "." + datetime();

    rename(logfile.c_str(), logFilename.c_str());
    rename(current.c_str(), logfile.c_str());   // install `logfile'

    imsg << "differences were observed: see `" << 
                 d_sorter["REPORT"] << "'  and `" << logfile << '\'' << endl;

    return false;
}


