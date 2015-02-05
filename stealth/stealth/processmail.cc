#include "stealth.ih"

void Stealth::processMail()
{
    if (d_options.logMail())
    {
        d_stealthReport.rewind();

        string line;
        while (getline(d_stealthReport.in(), line))
            imsg << "Mail: " << line << endl;
    }
    
    if (d_options.sendMail())
        sendMail();
}





