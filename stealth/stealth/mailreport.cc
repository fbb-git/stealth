#include "stealth.ih"

// Called from performTask()

void Stealth::mailReport()
{
    imsg << "Stealth::mailReport() starts" << endl;

    if (!d_reporter->hasMail())
    {
        imsg << "no report to mail" << endl;
        return;
    }

    d_reporter->rewind();                   // resets the `hasmail' variable

    if (d_options.reportToStdout())         // mail the report to stdout
    {
        imsg << "Stealth::mailReport() mails report to stdout" << endl;
        cout << d_reporter->in().rdbuf() << endl;
        return;
    }

    imsg << "mailing report using: " << (*d_policyFile)["MAILER"] << ' ' <<
            (*d_policyFile)["MAILARGS"] << " " << 
            (*d_policyFile)["EMAIL"] << endl;

    // mailcommand subject and email are called as separate arguments
    // If subject contains blanks, they will be interpreted as separate
    // arguments by the `mail' IOFork. Ususally d_policyFile["MAILER"] will
    // call a script.

    Process mail(Process::CIN | Process::IGNORE_COUT | Process::IGNORE_CERR,
                 (*d_policyFile)["MAILER"] + ' ' + 
                (*d_policyFile)["MAILARGS"] + ' ' + 
                 (*d_policyFile)["EMAIL"]);

    mail.start();

    for (string s; getline(d_reporter->in(), s); )
    {
        imsg << "Stealth::mailReport() contains: " << s << endl;
        mail << s << '\n';
    }
    
    mail.close();
    mail.waitForChild();

    imsg << "Report was mailed" << endl;
}

