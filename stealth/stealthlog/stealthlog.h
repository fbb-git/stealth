#ifndef STEALTHLOG_H_
#define STEALTHLOG_H_

#include <string>
#include <fstream>

class StealthLog: public std::ostream
{
    std::ios::pos_type   d_startSize = 0;
    std::ios::pos_type   d_beginMail = 0;

    std::fstream d_stealthlog;
    std::string  d_name;
    std::string d_headerLine;

    public:
        StealthLog() = default;
        
        StealthLog(StealthLog const &other) = delete;
        StealthLog &operator=(StealthLog const &other) = delete;

        void refresh();             // set d_beginMail to the log's EOF pos.
        void scanHeader();          // writes the integrity scan header,
                                    // initializes d_beginMail

        std::string const &headerLine() const;  // returns info about the
                                    // starting date/time of this stealth run

        std::istream &in();
        bool hasMail();             // true if there is info beyond d_beginMail

        void open(std::string const &name);
        void close();

        void rewind();              // prepare for reading
};

inline std::istream &StealthLog::in()
{
    return d_stealthlog;
}

inline void StealthLog::close()
{
    d_stealthlog.close();
}

#endif