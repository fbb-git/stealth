#include "stealth.ih"

void Stealth::processMail()
{
    imsg << "Mailing new logs using: " << (*d_policyFile)["MAILER"] << ' ' <<
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

    mail << d_log.headerLine() << '\n';

    string line;
    while (getline(d_log.in(), line))
    {
        imsg << "Mailing log line: " << line << endl;
        mail << line << '\n';
    }
    
    mail.close();
    mail.waitForChild();

    imsg << "Logs have been mailed" << endl;
}




