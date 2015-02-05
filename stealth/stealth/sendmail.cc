#include "stealth.ih"

void Stealth::sendMail()
{
    d_stealthReport.rewind();

    m3 << "Mailing new logs using: " << 
            (*d_policyFile)["MAILER"] << ' ' <<
            (*d_policyFile)["MAILARGS"] << " " << 
            (*d_policyFile)["EMAIL"] << endl;

    // mailcommand subject and email are called as separate arguments
    // If subject contains blanks, they will be interpreted as separate
    // arguments by the `mail' IOFork. Ususally d_policyFile["MAILER"] will
    // call a script.

    Process mail(
        Process::CIN | Process::IGNORE_COUT | Process::IGNORE_CERR,
        (*d_policyFile)["MAILER"]   + ' ' + 
            (*d_policyFile)["MAILARGS"] + ' ' + 
            (*d_policyFile)["EMAIL"]
    );

    mail.start();

    mail << d_stealthReport.headerLine() << '\n';

    string line;
    while (getline(d_stealthReport.in(), line))
        mail << line << '\n';

    mail.close();
    mail.waitForChild();
}
