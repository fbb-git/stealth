#include "monitor.ih"

void Monitor::mailReport()
{
    dout("Monitor::mailReport() starts");

    if (!d_reporter.hasText())
    {
        if (Util::debug())
            cerr << "no report to mail\n";
        return;
    }

    d_reporter.reset();

    if (Arg::getInstance().option("o"))     // mail the report to stdout
    {
        dout("Monitor::mailReport() mails report to stdout");
        cout << d_reporter.rdbuf() << endl;
        return;
    }

    if (Util::debug())
        cerr << "mailing report using: " << d_sorter["MAILER"] << 
            " " << d_sorter["MAILARGS"] << " " << d_sorter["EMAIL"] << endl;

    // mailcommand subject and email are called as separate arguments
    // If subject contains blanks, they will be interpreted as separate
    // arguments by the `mail' IOFork. Ususally d_sorter["MAILER"] will
    // call a script.

    IOFork mail(d_sorter["MAILER"] + " " + d_sorter["MAILARGS"] +
                    " " + d_sorter["EMAIL"]);

    mail.fork();            // call the script/program

    for (string s; getline(d_reporter, s); )
    {
        dout("Monitor::mailReport() contains: " << s);
        mail.out() << s << endl;
    }

    mail.waitForChild();
}





