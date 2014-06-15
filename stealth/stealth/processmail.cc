#include "stealth.ih"

void Stealth::processMail()
{
    switch (d_options.mailType())
    {
        case MailType::OFF:
        return;

        case MailType::LOG:
        {
            string line;
            while (getline(d_stealthLog.in(), line))
                imsg << "Mail line: " << line << endl;
        }
        break;
    
        case MailType::ON:
            sendMail();
        break;
    }
}





