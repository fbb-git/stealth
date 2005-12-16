#ifndef _REPORTER_H_
#define _REPORTER_H_

#include <fstream>
#include <bobcat/multistreambuf>

namespace FBB
{
    class Reporter: private MultiStreambuf, public std::ostream
    {
        static std::string  s_msg;

        unsigned long   d_sizeAtConstruction;
        std::string     d_name;
        bool            d_continue;
        bool            d_hasMail;

        std::fstream d_out;

        public:
            Reporter(std::string const &name); 

            void rewind();          // rewind to the position when
                                    // Reporter was constructed or at
                                    // the last reinit(). Information inserted
                                    // after calling this member will be
                                    // extracted

            std::istream &in()
            {
                return d_out;
            }

            bool hasMail() const
            {
                return d_hasMail;
            }

            void relax();           // close the report file, release a 
                                    // runfile lock
            void standby();         // obtain a runfile lock, open the report
                                    // file

            std::ostream &exit();   // inserts a message and exits,
                                    // writing the same message to stderr,
                                    // and throwing ERROR.
        private:
            virtual int sync();

            void reinit();

            Reporter(Reporter const &other);            // NI
            Reporter &operator=(Reporter const &other); // NI
    };
}
#endif
