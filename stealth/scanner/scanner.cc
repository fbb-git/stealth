#include "scanner.h2"

/*
    Since the Scanner's destruction is also the termination of the program, no
explicit destruction of the newly created objects is necessary. A pointer is
used to prevent the construction of a constant object. As the constructor
itself would create a constant object, the construction *new... 
is used.

*/

Scanner::Scanner(ConfigSorter &sorter)
:
    d_sorter(sorter),
    d_reporter(*new Reporter(sorter["REPORT"])),// ostream
    d_firstWord(*new Pattern("(\\S+)\\s+(.*)")),// firstword ([1]) and 
                                                // the rest ([2]) of a text
    d_sshFork(d_sorter["SSH"]),                 // child: ignores stderr, reads
    d_shFork(d_sorter["SH"]),                   // from stdin/stdout
                                                // parent process communicates
                                                // via the Fork object's 
                                                // stream interface.
    d_debug(Arg::getInstance().option('d'))     // debug requested
{
    ostringstream oss;

    oss << "EOC " << Util::date;
    d_sentinel = oss.str();
}
