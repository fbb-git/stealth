#include "stealth.ih"

// automatically switch to an integrity scan after reload, rerun and resume.

void Stealth::autoScan(char const *label)
{
    d_task.setMode(INTEGRITY_SCAN);

    m2 << "automatically starting an INTEGRITY_SCAN following --" << label 
                                                                    << endl;
    d_processor.notify();
    d_result.notify();

    // 
}
