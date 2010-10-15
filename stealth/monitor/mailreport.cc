#include "monitor.ih"

// Called from control()

void Monitor::mailReport()
{
    Util::debug() << "Monitor::mailReport() starts\n";

    if (!d_reporter.hasMail())
    {
        Util::debug() << "no report to mail\n";
        return;
    }

    d_reporter.rewind();                    // resets the `hasmail' variable

    if (Arg::instance().option('o'))     // mail the report to stdout
    {
        Util::debug() << "Monitor::mailReport() mails report to stdout" << 
                                                                        "\n";
        cout << d_reporter.in().rdbuf() << endl;
        return;
    }

    Util::debug() << "mailing report using: " << d_sorter["MAILER"] << 
            " " << d_sorter["MAILARGS"] << " " << d_sorter["EMAIL"] << "\n";

    // mailcommand subject and email are called as separate arguments
    // If subject contains blanks, they will be interpreted as separate
    // arguments by the `mail' IOFork. Ususally d_sorter["MAILER"] will
    // call a script.

    Process mail(Process::CIN | Process::IGNORE_COUT | Process::IGNORE_CERR,
                 d_sorter["MAILER"] + ' ' + d_sorter["MAILARGS"] + ' ' + 
                 d_sorter["EMAIL"]);

    mail.start();

    for (string s; getline(d_reporter.in(), s); )
    {
        Util::debug() << "Monitor::mailReport() contains: " << s << "\n";
        mail << s << "\n";
    }
    
    mail.close();
    mail.waitForChild();

    Util::debug() << "Mailing report\n";
}

