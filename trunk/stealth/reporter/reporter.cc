#include "reporter.ih"

Reporter::Reporter(string const &name)
:
    MultiStreambuf(cerr, RESET),
    ostream(this),      // initialize the ostream with the MultiStreambuf
    d_name(name),
    d_continue(true),
    d_hasMail(false)
{
    insert(d_out);                              // insertions go to the report

    // no further initialization of the Reporter is required here. In
    // particular, the logfile is not yet opened. I wait until Stealth
    // runs (maybe) in the background. The Monitor will then lock the runfile
    // and start logging.
}




