#include "logunit.ih"

// If --log was requested, define the logbuffer. 
// If --syslog was requested define the syslogbuf
// If either fails, send fmsg.
//
// If both succeed messages inserted into imsg (and so: into m1..m3) are sent
// to all logfiles; if --stdout has also been specified then imsg also inserts
// into cout.
//
// fmsg, after setuplogs also inserts into the mail, and pending mail is
// delivered when the mail object is destroyed.

void LogUnit::setupLogs()
{
    unique_ptr<ostream> log(newLog());
    unique_ptr<ostream> syslog(newSyslogStream());

    unique_ptr<MultiStreambuf> imsgbuf(new MultiStreambuf);
    
    if (log.get() != 0)
    {
        d_log.swap(log);            // install the new Log
        imsgbuf->insert(*d_log);
    }

    if (syslog.get() != 0)
    {
        d_syslog.swap(syslog);      // install the new syslogbuf
        imsgbuf->insert(*d_syslog);
    }

    if (d_options.stdout())
        imsgbuf->insert(cout);

    if (imsgbuf->begin() != imsgbuf->end())
    {
        d_imsgbuf.swap(imsgbuf);
        imsg.reset(d_imsgbuf.get());
    }

    unique_ptr<MultiStreambuf> fmsgbuf(new MultiStreambuf);
    fmsgbuf->insert(imsg);
    d_fmsgbuf.swap(fmsgbuf);

    fmsg.reset(d_fmsgbuf.get());
}
