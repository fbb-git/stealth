#include "monitor.ih"

// Called from control()

namespace{
unsigned x;
}

void Monitor::mailReport()
{
    Util::debug() << "Monitor::mailReport() starts" << endl;

    if (!d_reporter.hasMail())
    {
        Util::debug() << "no report to mail" << endl;
        return;
    }

//    ofstream out("/tmp/stealth", ios::app);
//    out << ++x << ": reporter signals `has mail'\n";
    
    d_reporter.rewind();                    // resets the `hasmail' variable

    if (Arg::instance().option("o"))     // mail the report to stdout
    {
        Util::debug() << "Monitor::mailReport() mails report to stdout" << 
                                                                        endl;
        cout << d_reporter.rdbuf() << endl;
        return;
    }

    Util::debug() << "mailing report using: " << d_sorter["MAILER"] << 
            " " << d_sorter["MAILARGS"] << " " << d_sorter["EMAIL"] << endl;

    // mailcommand subject and email are called as separate arguments
    // If subject contains blanks, they will be interpreted as separate
    // arguments by the `mail' IOFork. Ususally d_sorter["MAILER"] will
    // call a script.

    Process mail(5, d_sorter["MAILER"] + " " + d_sorter["MAILARGS"] +
                    " " + d_sorter["EMAIL"], Process::CIN | 
                                             Process::IGNORE_COUT |
                                             Process::IGNORE_CERR);

    mail.start(Process::USE_SHELL);

    for (string s; getline(d_reporter.in(), s); )
    {
        Util::debug() << "Monitor::mailReport() contains: " << s << endl;
        mail << s << endl;
    }

    Util::debug() << "Mailing report" << endl;
}
