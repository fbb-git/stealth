#ifndef LOG_H_
#define LOG_H_

#include <string>
#include <fstream>
#include <bobcat/multistreambuf>

class Log: private FBB::MultiStreambuf, public std::ostream
{
    std::ios::pos_type   d_startSize = 0;
    std::ios::pos_type   d_beginMail = 0;

    std::fstream d_log;
    std::string  d_name;
    std::string d_headerLine;

    public:
        Log(); 

        Log(Log const &other) = delete;
        Log &operator=(Log const &other) = delete;

        void header();
        void scanHeader();
        std::string const &headerLine() const;

        std::istream &in();
        bool hasMail();

        void open(std::string const &name);
        void close();

        void rewind();              // prepare for reading

    private:
        virtual int sync();
};

inline std::istream &Log::in()
{
    return d_log;
}

inline void Log::close()
{
    d_log.close();
}

#endif
