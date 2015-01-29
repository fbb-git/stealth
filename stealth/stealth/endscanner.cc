#include "stealth.ih"

void Stealth::endScanner()
{
    if (d_scanThread.joinable())
        d_scanThread.join();
}
