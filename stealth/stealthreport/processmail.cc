#include "stealthreport.ih"

void StealthReport::processMail()
{
    if (d_options.logMail())
    {
        rewind();

        string line;
        while (getline(*this, line))
            imsg << "Mail: " << line << endl;
    }
    
    if (d_options.sendMail())
        sendMail();

    refresh();
}
