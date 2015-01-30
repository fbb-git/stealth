#include "stealth.ih"

void Stealth::rerun()
{
    d_stealthLog << "STEALTH explicit integrity scan rerun at " <<
                    d_options.rfc2822() << endl;

    endScanner();                               // wait for an ongoing scan to
                                                // end

    autoScan("rerun");
}
