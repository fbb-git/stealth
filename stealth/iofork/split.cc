#include "iofork.ih"

/*
    Patroon:    (^|[^\\])("(([^"]|\\.)*)")

    Patroon:    ( ^ | [^\\] ) ( " ( ( [^"] | \\. ) * ) " )
    element:      1   2         3 4   5      6   7 8   9
    subexpr:    1             2   3           

    Element:    1 begin of line
                2 or no backslash       - 1,2 get the last char before "
                3 opening double quote
                    4: begin multiplication-group
                        5: no double quote
                        6: or backslash + any other char
                    7: end multiplication group
                    8: group 4-7: any number of times
                9 closing double quote

    Subexpr:
                1: the initial character (may be empty)
                2: the quoted string, including quotes
                3: the quoted string, excluding quotes

    Both single-quoted and double quoted matches are allowed. If they overlap,
    the first string is used as the matching string. e.g.,

        "   '   "   '

    Will match: 

        "   '   "   

    as a double string,
    and a second argument   '   is recognized.

*/          


namespace
{
    void split(vector<string> &vs, string const &src)
    {
        string text(src);

        dout("IOFork::split(): " << src);
    
        static Pattern element("\\S+");         // a blank-delimited element
    
        while (element << text)                 // find it ?
        {
            dout("IOFork::split(): push " << element.match());

            vs.push_back(element.matched());      // yes, push back
            text = element.beyond();           // remove the element from text
        }
    }
}
                
char const **IOFork::split(vector<string> &vs)
{
    static Pattern dquoted("(^|[^\\\\])(\"(([^\"]|\\\\.)*)\")");
    static Pattern squoted("(^|[^\\\\])('(([^\"]|\\\\.)*)')");

    dout("IOFork::split: " << d_cmd);

                                            // while we have a dquoted 
                                            // or squoted match
    while ((dquoted << d_cmd) || (squoted << d_cmd))    
    {
        string::size_type
            dq = dquoted.position(0).first,
            sq = squoted.position(0).first;
        bool
            processSquoted;

        if (sq != string::npos)             // matched a single quoted string
            processSquoted =                // process it if:
                dq == string::npos          // no double quoted string
                ||                          // or single before double
                sq < dq;                  
        else                                // or matched only
            processSquoted = false;         // a double quoted str.    

        if (processSquoted)
        {
            dout("IOFork::split(): squote - before: " << squoted.before());
            dout("IOFork::split(): squote -  match: " << squoted.match());
            dout("IOFork::split(): squote - beyond: " << squoted.beyond());

            ::split(vs, squoted.before() + squoted[1]); // split prefix

            dout("IOFork::split(): push " << squoted[2]);
            vs.push_back(squoted[2]);                   // push the quoted str.
            d_cmd = squoted.beyond();                   // process next
        }
        else                                // process d-quoted string
        {
            dout("IOFork::split(): dquote - before: " << dquoted.before());
            dout("IOFork::split(): dquote -  match: " << dquoted.match());
            dout("IOFork::split(): dquote - beyond: " << dquoted.beyond());

            ::split(vs, dquoted.before() + dquoted[1]); // split prefix

            dout("IOFork::split(): push " << dquoted[2]);
            vs.push_back(dquoted[2]);                   // push the string
            d_cmd = dquoted.beyond();                   // process next
        }
    }

    ::split(vs, d_cmd);                     // split the remainder

                                            // array of pointers to strings
    char const **argv = new char const *[vs.size() + 1];

                                            // point to elements
    for (unsigned idx = 0; idx < vs.size(); idx++)
        argv[idx] = vs[idx].c_str();

    argv[vs.size()] = 0;                    // and terminate

    return argv;
}



