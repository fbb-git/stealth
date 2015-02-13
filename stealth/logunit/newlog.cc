#include "logunit.ih"

ostream *LogUnit::newLog()
try
{
    string const &name = d_options.logName();
    return name.empty() ? 0 : new Log(name); 
}
catch (exception const &exc)
{
    fmsg << "cannot write log file `" << d_options.logName() << '\'' << noidl;
    return 0;       // to make the compiler happy
}
