#include <iostream>
#include <string>

using namespace std;

#include "../../VERSION"

#include "../../version.cc"
#include "../../options/options.h"
#include "../../options/data.cc"
#include "../../options/usage.cc"

int main(int argc, char **argv)
{
    Options::usage("stealth");
    return 0;
}
