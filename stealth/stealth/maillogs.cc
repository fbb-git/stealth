#include "stealth.ih"

// Called from performTask()

void Stealth::mailLogs()
{
    if (not d_log.hasMail())
    {
        imsg << "No new logs available" << endl;
        return;
    }

    d_log.rewind();

    if (d_options.reportToStdout())         // mail the report to stdout
    {
        imsg << "New logs to stdout" << endl;

        cout << d_log.headerLine() << d_log.in().rdbuf() << endl;
        return;
    }

    processMail();
}

