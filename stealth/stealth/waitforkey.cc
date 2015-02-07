#include "stealth.ih"

void Stealth::waitForKey()
{
    cin.ignore(numeric_limits<int>::max(), '\n');
    imsg << "STEALTH (foreground) TERMINATED by user-request" << endl;
    d_task.setMode(TERMINATE);
    d_job.notify();
}

