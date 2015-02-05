#include "stealth.ih"

void Stealth::rerun()
{
    d_stealthReport << "STEALTH explicit integrity scan rerun at " <<
                    d_options.rfc2822() << endl;

    autoScan("rerun");
}
