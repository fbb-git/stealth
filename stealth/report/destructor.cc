#include "report.ih"

Report::~Report()
{
    if (hasMail())
        processMail();
}
