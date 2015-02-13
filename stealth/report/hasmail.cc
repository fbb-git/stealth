#include "report.ih"

bool Report::hasMail() 
{
    return d_beginMail < endpos();
}

