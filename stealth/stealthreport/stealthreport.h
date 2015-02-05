#ifndef STEALTHREPORT_H_
#define STEALTHREPORT_H_

#include <string>
#include <fstream>

class StealthReport: public std::ostream
{
    std::ios::pos_type   d_startSize = 0;
    std::ios::pos_type   d_beginMail = 0;

    std::fstream d_stealthreport;
    std::string  d_name;
    std::string d_headerLine;

    public:
        StealthReport() = default;
        
        StealthReport(StealthReport const &other) = delete;
        StealthReport &operator=(StealthReport const &other) = delete;

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

inline std::istream &StealthReport::in()
{
    return d_stealthreport;
}

inline void StealthReport::close()
{
    d_stealthreport.close();
}

#endif
