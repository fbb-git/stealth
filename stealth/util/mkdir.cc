#include "util.h2"

bool Util::mkdir(string const &path)
{
    char buffer[path.length() + 1];

    buffer[path.copy(buffer, string::npos)] = 0;    // copy the path
    char const *dir = dirname(buffer);              // construct the dirname

    return
    (
        !::mkdir(dir, S_IRWXU)                      // constructing dir ok,
        ||                                          //      (only drwx------)
        errno == EEXIST                             // or dir already existed
    );
}
