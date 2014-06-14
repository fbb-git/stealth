#include "integrityscanner.ih"

void IntegrityScanner::checkSize(std::string const &fname, off_t length)
{
    if (length > d_maxSize)
        d_log << 
            "STEALTH - CAN'T CONTINUE: `" << fname << "' EXCEEDS MAX. "
                                "DOWNLOAD SIZE (" << d_maxSizeStr << ")\n" 
            "STEALTH - THIS COULD POINT TO A SERIOUS SITUATION EXISTING AT "
                                                            "THE CLIENT\n"
            "STEALTH - THIS CONDITION MAY HAVE INVALIDATED THE CLIENT'S LOG "
                                                            "FILES\n" 
            "STEALTH - *** INVESTIGATE ***" << ModeEnum::leave;
}





