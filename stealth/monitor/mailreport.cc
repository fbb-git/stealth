#include "monitor.ih"

void Monitor::mailReport()
{
    Util::debug() << "Monitor::mailReport() starts" << endl;

    if (!d_reporter.hasMail())
    {
        Util::debug() << "no report to mail" << endl;
        return;
    }

    d_reporter.rewind();

    if (Arg::getInstance().option("o"))     // mail the report to stdout
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

    IOFork mail(d_sorter["MAILER"] + " " + d_sorter["MAILARGS"] +
                    " " + d_sorter["EMAIL"]);

    mail.fork();            // call the script/program

    for (string s; getline(d_reporter.in(), s); )
    {
        Util::debug() << "Monitor::mailReport() contains: " << s << endl;
        mail.out() << s << endl;
    }

    mail.waitForChild();
}





