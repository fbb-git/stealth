#ifndef _REPORTER_H_
#define _REPORTER_H_

#include <fstream>
#include <bobcat/multistreambuf>

class Reporter: private FBB::MultiStreambuf, public std::ostream
{
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

        std::istream &in();
        bool hasMail() const;

        bool relax();           // close the report file, release a 
                                // runfile lock, returns d_continue

        void standby();         // obtain a runfile lock, open the report
                                // file

        std::ostream &error();  // inserts a message and prepares for 
                                // exit. The error message is also written
                                // to stderr. Once `sync()' is called,
                                // the program ends in an Errno(1)

    private:
        virtual int sync();

        void reinit();

        Reporter(Reporter const &other);            // NI
        Reporter &operator=(Reporter const &other); // NI
};

inline std::istream &Reporter::in()
{
    return d_out;
}

inline bool Reporter::hasMail() const
{
    return d_hasMail;
}

#endif








