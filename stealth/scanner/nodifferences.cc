#include "scanner.h2"

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
    dout("Scanner::noDifferences(): started " << d_sorter["DIFF"] << \
                                    " " << current << " " << logfile);

    d_shFork.out() << d_sorter["DIFF"] << " " << current << " " << logfile <<
                                                                    endl <<
                        "/bin/echo \"" << d_sentinel << "\"" << endl;

    StringHash< pair<string, vector<string> > >
        status;

    dout("Scanner::noDifferences():         " << "/bin/echo " << d_sentinel);

    /*
        key is string, case sensitive.

        The last element of the lines produced by diff is used as the
        key. For the current function to operate sensibly, this should be
        a filename or path/file.

        If the first character of the line is a < or >, then a modification is
        detected: for these lines the following happens:
            1. If the key already existed its .first element is set to
                "modified". If the key didn't exist yet, it is set to
                "added" at at '<', and to "removed" at a '>'
            2. The line itself is pushed back to the .second (vector) element
                of the pair.

        At the end, if the hashtable has any elements, the table is inserted
        into the d_reporter and `false' is returned. If the hashtable contains
        no elements, 'true' is returned.
    */

    string  s;
    Pattern split("(\\S+)\\s*$");

    dout("Scanner::noDifferences(): starting to read lines");

    if (!d_shFork.in())
        Util::exit(1, "`%s': no output from %s", d_sorter["SH"].c_str(), 
                                                d_sorter["DIFF"].c_str());

    while (getline(d_shFork.in(), s))
    {
        dout("Scanner::noDifferences():      got: `" << s << "'");
        dout("Scanner::noDifferences(): sentinel: `" << d_sentinel << "'");

        if (s == d_sentinel)
            break;

        if (!split.match(s))
            continue;                       // no match at empty lines ?

        string key = split[1];              // get the key
        bool exists = status.count(key);

        if (s[0] == '>')                // removal, e.g.,   > b88d0b....  out
                status[key].first = exists ? "MODIFIED" : "REMOVED";
        else if (s[0] == '<')
                status[key].first = exists ? "MODIFIED" : "ADDED";
        else
            continue;

        status[key].second.push_back(s);
    }

    if (!status.size())                 // no elements ?
    {
        if (d_debug)
            cerr << "no differences were observed\n";

        rename(current.c_str(), logfile.c_str());   // install `logfile'
        return true;                   // nothing to report
    }


    if (d_label.length())
        d_reporter << d_label << endl;

    for
    (
        StringHash< pair<string, vector<string> > >::iterator
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

    string
        datetime = logfile + "." + Util::datetime();

    rename(logfile.c_str(), datetime.c_str());
    rename(current.c_str(), logfile.c_str());   // install `logfile'

    if (d_debug)
        cerr << "differences were observed: see `" << 
                 d_sorter["REPORT"] << "'  and `" << logfile << "'" << endl;

    return false;
}


