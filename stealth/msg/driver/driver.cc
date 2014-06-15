#include "../msg.h"

using namespace std;

int main()
{
    m1 << "m1" << endl;

    Msg::setVerbosity(0);
    m1 << "invisible" << endl;

    Msg::setVerbosity(1);
    m1 << "visible" << endl;
    m2 << "invisible" << endl;
}
