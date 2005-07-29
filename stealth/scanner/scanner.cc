#include "scanner.h2"

/*
    Since the Scanner's destruction is also the termination of the program, no
explicit destruction of the newly created objects is necessary. A pointer is
used to prevent the construction of a constant object. As the constructor
itself would create a constant object, the construction *new... 
is used.

*/

Scanner::Scanner(ConfigSorter &sorter, Reporter &reporter)
:
    d_sorter(sorter),
    d_reporter(reporter),// ostream
    d_firstWord(*new Pattern("(\\S+)(\\s+(.*))?")),// firstword ([1]) and 
                                                // the rest ([3]) of a text
    d_sshFork(d_sorter["SSH"]),                 // child: ignores stderr, reads
    d_shFork(d_sorter["SH"]),                   // from stdin/stdout
                                                // parent process communicates
                                                // via the Fork object's 
                                                // stream interface.
    d_nScans(0)
{
    setSentinel();
}

