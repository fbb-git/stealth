#include "pattern.h2"

namespace FBB
{

Pattern::conversion
    Pattern::patmod[] = 
    {
        conversion("\\d", "[0-9]"),
        conversion("\\D", "[^0-9]"),
        conversion("\\s", "[ \t\r\n]"),
        conversion("\\S", "[^ \t\r\n]"),
    };

unsigned
    Pattern::sizeofPatmod = 4;

}
