#include <iostream>
#include <string>

using namespace std;

#include "../../VERSION"

#include "../../util/usage2.cc"

int main(int argc, char **argv)
{
    usage("stealth", VERSION, YEARS);
    return 0;
}
