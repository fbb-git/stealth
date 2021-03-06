#include "integrityscanner.ih"

/*
    Since the IntegrityScanner's destruction is also the termination of the
program, no explicit destruction of the newly created objects is necessary. A
pointer is used to prevent the construction of a constant object. As the
constructor itself would create a constant object, the construction *new...
is used.

*/

IntegrityScanner::IntegrityScanner(RunMode const &pending, Options &options,
                                PolicyFile &policyFile, ostream &report)
:
    d_options(options),
    d_pending(pending),
    d_policyFile(policyFile),
    d_report(report),
    d_firstWord("(\\S+)(\\s+(.*))?"),           // firstword ([1]) and the
                                                // rest ([3]) of a text
    d_sshFork
    (
        Process::CIN | Process::COUT | Process::IGNORE_CERR,
        d_policyFile["SSH"]
    ),                 // child: ignores stderr, reads
    d_shFork
    (
        Process::CIN | Process::COUT | Process::IGNORE_CERR,
        d_policyFile["SH"]
    ),                   // from stdin/stdout
                                                // parent process communicates
                                                // via the Fork object's 
                                                // stream interface.
    d_nScans(0),
    d_maxSize(d_options.maxDownloadSize()),

    d_diffPrefix(stoul(d_policyFile["DIFFPREFIX"])),
    d_pathOffset(numeric_limits<size_t>::max())
{
    setSentinel();
    loadSkipFiles();                    
}
