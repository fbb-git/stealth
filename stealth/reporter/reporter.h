#ifndef _REPORTER_H_
#define _REPORTER_H_

#include <fstream>

namespace FBB
{
    class Reporter: public std::fstream    
    {
        static std::string  s_msg;

        unsigned long d_sizeAtConstruction;
        unsigned long d_sizeBeyondHeader;
        std::string d_name;

        public:
            Reporter(std::string const &name); // first time

            void reset();           // reset to the position when
                                    // Reporter was constructed or at
                                    // the last reinit(). Information inserted
                                    // after calling this member will be
                                    // extracted

            bool hasText()
            {
                return static_cast<unsigned long>(tellp())
                        > d_sizeBeyondHeader;
            }

            void reinit();

        private:
            Reporter(Reporter const &other);            // NI
            Reporter &operator=(Reporter const &other); // NI
    };
}
#endif
