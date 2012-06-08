#include "monitor.ih"

// Called from control()

void Monitor::mailReport()
{
    imsg << "Monitor::mailReport() starts" << endl;

    if (!d_reporter->hasMail())
    {
        imsg << "no report to mail" << endl;
        return;
    }

    d_reporter->rewind();                   // resets the `hasmail' variable

    if (d_arg.option('o'))                  // mail the report to stdout
    {
        imsg << "Monitor::mailReport() mails report to stdout" << endl;
        cout << d_reporter->in().rdbuf() << endl;
        return;
    }

    imsg << "mailing report using: " << (*d_sorter)["MAILER"] << ' ' <<
            (*d_sorter)["MAILARGS"] << " " << (*d_sorter)["EMAIL"] << endl;

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
        imsg << "Monitor::mailReport() contains: " << s << endl;
        mail << s << '\n';
    }
    
    mail.close();
    mail.waitForChild();

    imsg << "Mailing report" << endl;
}

