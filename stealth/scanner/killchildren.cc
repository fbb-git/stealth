#include "scanner.h2"

void Scanner::killChildren()
{
    kill(0, SIGTERM) && kill(0, SIGKILL);
}
