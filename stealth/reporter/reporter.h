#ifndef _REPORTER_H_
#define _REPORTER_H_

#ifndef _SYSINC_FSTREAM_
#include <fstream>
#define _SYSINC_FSTREAM_
#endif

namespace FBB
{
    class Reporter: public std::fstream    
    {
        unsigned long d_sizeAtConstruction;
        unsigned long d_sizeBeyondHeader;

        static std::string  s_msg;

        public:
            Reporter(std::string const &name); // first time

            void reset();           // reset to the EOF position when
                                    // Reporter was constructed. Extracts
                                    // after this retrieve added information

            bool hasText()
            {
                return static_cast<unsigned long>(tellp())
                        > d_sizeBeyondHeader;
            }

        private:
            Reporter(Reporter const &other);            // NI
            Reporter &operator=(Reporter const &other); // NI
    };
}
#endif
