#include "configfile.h2"

char const *ConfigFile::get(std::string const &name) const
{
    for 
    (
        std::vector<std::string>::const_iterator it = d_lines.begin();
            it != d_lines.end();
                it++
    )
    {
        if (find(name, &*it))
            return it->c_str();
    }    
    return 0;
}   
