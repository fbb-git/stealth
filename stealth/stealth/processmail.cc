#include "stealth.ih"

void Stealth::processMail()
{
    if (d_options.logMail())
    {
        d_stealthLog.rewind();

        string line;
        while (getline(d_stealthLog.in(), line))
            imsg << "Mail line: " << line << endl;
    }
    
    if (d_options.sendMail())
        sendMail();
}





