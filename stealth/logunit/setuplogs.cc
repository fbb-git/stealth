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

LogUnit::setupLogs()
{
    unique_ptr<streambuf> logbuf(newLogBuf());
    unique_ptr<streambuf> syslogbuf(newSysLogBuf());

    unique_ptr<MultiStreambuf> imsgBuf(new MultiStreambuf);
    
    if (logbuf.get() != 0)
    {
        d_logbuf.swap(logbuf);          // install the new logbuf
        d_log.rdbuf(d_logbuf.get());
        imsgBuf->insert(d_log);
    }

    if (syslogbuf.get() != 0)
    {
        d_syslogbuf.swap(syslogbuf);    // install the new syslogbuf
        d_syslog.rdbuf(d_syslogbuf.get());
        imsgBuf->insert(d_syslog);
    }

    if (d_options.stdout())
        imsgBuf->insert(cout);

    if (imsgBuf.begin() != imsgBuf.end())
    {
        d_imsgBuf.swap(imsgBuf);
        imsg.reset(d_imsgBuf.get());
    }

    unique_ptr<MultiStreambuf> fmsgbuf(new MultiStreambuf);
    fmsgbuf->insert(imsg);
    d_fmsgbuf.swap(fmsgbuf);

    fmsg.reset(d_fmsg.get(), 
               std::numeric_limits<size_t>::max(), "Fatal", true);

}
