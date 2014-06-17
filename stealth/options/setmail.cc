#include "options.ih"

    // by default mail is ON

void Options::setMail()
{
    d_logMail = d_arg.option(0, "log-mail");
    d_sendMail = not d_arg.option(0, "no-mail");
}





