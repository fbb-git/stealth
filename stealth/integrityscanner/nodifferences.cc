#include "integrityscanner.ih"

/*
    Example of diff-output:

33c33
< 90d8b506d249634c4ff80b9018644567  out
---
> b88d0b77db74cc4a742d7bc26cdd2a1e  out

*/

bool IntegrityScanner::noDifferences(std::string const &current,
                                  std::string const &logfile)
{
    m3 << "noDifferences() started: " << 
            d_policyFile["DIFF"] << " " << current << " " << logfile << endl;

    d_shFork << d_policyFile["DIFF"] << " " << current << " " << logfile <<
                                                                     '\n' <<
                        "/bin/echo \"" << d_sentinel << "\"" << endl;

    typedef  LinearMap<string, pair<string, vector<string>>> LinMap;

//    HashString<pair<string, vector<string>>> status;
    LinMap status;

    m3 << "noDifferences():         /bin/echo " << d_sentinel << endl;

    //  status's key is a case sensitive string.
    //
    //  The last element of the lines produced by diff is used as the
    //  key. For the current function to operate sensibly, this should be
    //  a filename or a path/file.
    //
    //  If the first character of the line is a < or >, then a modification is
    //  detected: for these lines the following happens:
    //      1. If the key already exists then its .first element is set to
    //          "modified". When a '<' was seen and if the key doesn't yet 
    //          exist, it is set to "added". 
    //          If the pathname is found in the array of files to skip
    //          or if the pathname truncated at the last '/' is found in the
    //          d_skipFiles array it is set to "skipping". Otherwise
    //          it's set to "removed".
    //      2. The line itself is pushed back to the .second (vector) element
    //          of the pair.
    //
    //  At the end, if the hashtable has any elements, the table is inserted
    //  into the d_report and `false' is returned. If the hashtable contains
    //  no elements, 'true' is returned.

    string  line;

    // get lines from diff, lines like:
    //    
    //    33c33
    //    < 90d8b506d249634c4ff80b9018644567  out
    //    ---
    //    > b88d0b77db74cc4a742d7bc26cdd2a1e  out

    m3 << "check differences: sentinel = `" << d_sentinel << '\'' << endl;

    while (getline(d_shFork, line))
    {
        m3 << "check differences. line = `" << line << '\'' << endl;
                                           

        if (line == d_sentinel)            // done at the sentinel
            break;

                                        // get the target (path) from the line
                                        // (ignoring the diff-prefix)
        string path = getPath(line.substr(d_diffPrefix));


            // find out whether we have to skip this entry or not. If so
            // remove the filename from orgLine:
        bool skipEntry = (this->*d_skip)(path);
            
            // now we'll process skipped elements by their path-name
            // and other elements remain as-is
        bool exists = status.count(path);    

        if (line[0] == '<')
                status[path].first = exists ? "MODIFIED" : "ADDED";
        else if (line[0] == '>')   // removal or skip, e.g.,   > b88d0b....  out
            status[path].first = skipEntry ? "SKIPPING" :
                                        exists ? "MODIFIED" : "REMOVED";
        else
            continue;

        status[path].second.push_back(line);
    }

    if (!status.size())                 // no elements ?
    {
        m3 << "no differences observed" << endl;

        rename(current.c_str(), logfile.c_str());   // install `logfile'
        return true;                   // nothing to report
    }

    if (d_label.length())
        d_report << d_label << endl;

    for
    (
//        HashString< pair<string, vector<string> > >::iterator
        LinMap::iterator begin = status.begin(), end = status.end();
            begin != end;
                begin++
    )
    {
        d_report << begin->second.first  << ": " << begin->first << endl;

        for
        (
            vector<string>::iterator
                sbegin = begin->second.second.begin(),
                send = begin->second.second.end();
                    sbegin != send;
                        sbegin++
        )
            d_report << "    " << *sbegin << endl;
    }

    string logFilename = logfile + "." + datetime();

    rename(logfile.c_str(), logFilename.c_str());
    rename(current.c_str(), logfile.c_str());   // install `logfile'

    m1 << "differences observed: see `" << 
             d_policyFile["REPORT"] << "'  and `" << logfile << '\'' << endl;

    return false;
}


