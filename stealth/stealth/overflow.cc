#include "stealth.ih"

int LogReportbuf::overflow(int ch) 
{
    if (ch != EOF)
        d_report.put(ch);
    return ch;
}
