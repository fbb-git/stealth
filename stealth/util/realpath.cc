#include "util.ih"

#include <iostream>

string Util::realPath(string const &path)
{
    String::Type type;
    vector<string> component = String::split(&type, path, "/");

    if (type != String::NORMAL)
        throw Exception() << "Filename `" << path << "': not supported";

    component.resize(
                    remove(component.begin(), component.end(), ".")
                    - 
                    component.begin()
                );

    while (true)
    {
        size_t from = find(component.begin(), component.end(), "..") 
                      - component.begin();

        if (from == component.size())      // at the last entry: done
            break;

        size_t to = find_if(component.begin() + from + 1, component.end(),
                        [&](string const &element)
                        {
                            return element != "..";
                        }
                    ) - component.begin();


        size_t count = to - from;               // # ".." entries

        size_t firstErase = from >= count ?     // first to erase
                                from - count
                            :
                                0;

        component.erase(component.begin() + firstErase,
                        component.begin() + to);
    }

    string ret(1, '/');

    for(auto &str: component)
        ret += str + '/';

    ret.pop_back();

    return ret;
}
