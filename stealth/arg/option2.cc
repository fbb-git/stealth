#include "arg.ih"

bool Arg::option(int optchar, string &value) const
{
    static bool called = false;
    if (!called)
    {
        called = true;
        cerr << 
            "`bool FBB::Arg::option(int optchar, string &value) const'\n" <<
            "is deprecated because of the `return by argument' convention." << 
                                                                " Use:\n" <<
            "`bool FBB::Arg::option(string *value, int optchar) const'\n";
    }

    return option(&value, optchar);
}
