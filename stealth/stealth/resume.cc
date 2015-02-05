#include "stealth.ih"

void Stealth::resume()
{
    d_stealthReport << "STEALTH resumes its tasks at " << d_options.rfc2822() << 
                                                                        endl;

    autoScan("resume");
}
