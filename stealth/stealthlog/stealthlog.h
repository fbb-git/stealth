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

        void header();
        void scanHeader();
        std::string const &headerLine() const;

        std::istream &in();
        bool hasMail();

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
