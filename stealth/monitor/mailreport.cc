#include "monitor.ih"

// Called from control()

void Monitor::mailReport()
{
    msg() << "Monitor::mailReport() starts" << info;

    if (!d_reporter->hasMail())
    {
        msg() << "no report to mail" << info;
        return;
    }

    d_reporter->rewind();                    // resets the `hasmail' variable

    if (Arg::instance().option('o'))     // mail the report to stdout
    {
        msg() << "Monitor::mailReport() mails report to stdout" << info;
        cout << d_reporter->in().rdbuf() << endl;
        return;
    }

    msg() << "mailing report using: " << (*d_sorter)["MAILER"] << ' ' <<
            (*d_sorter)["MAILARGS"] << " " << (*d_sorter)["EMAIL"] << info;

    // mailcommand subject and email are called as separate arguments
    // If subject contains blanks, they will be interpreted as separate
    // arguments by the `mail' IOFork. Ususally d_sorter["MAILER"] will
    // call a script.

    Process mail(Process::CIN | Process::IGNORE_COUT | Process::IGNORE_CERR,
                 (*d_sorter)["MAILER"] + ' ' + (*d_sorter)["MAILARGS"] + ' ' + 
                 (*d_sorter)["EMAIL"]);

    mail.start();

    for (string s; getline(d_reporter->in(), s); )
    {
        msg() << "Monitor::mailReport() contains: " << s << info;
        mail << s << "\n";
    }
    
    mail.close();
    mail.waitForChild();

    msg() << "Mailing report" << info;
}

