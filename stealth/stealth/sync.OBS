#include "stealth.ih"

int FatalBuffer::sync()
{
    d_stealth.d_stealthReport << d_msg << flush;
    d_stealth.d_options.setLogMail();
    d_stealth.processMail();

    cerr << d_msg;

    return 0;
}
