#include "report.ih"

void Report::processMail()
{
    if (d_options.logMail())
    {
        rewind();

        string line;
        while (std::getline(*this, line))
            imsg << "Mail: " << line << endl;
    }
    
    if (d_options.sendMail())
        sendMail();

    refresh();
}
