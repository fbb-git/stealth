#ifndef STEALTHREPORT_H_
#define STEALTHREPORT_H_

#include <string>
#include <fstream>

class Options;
class PolicyFile;

class StealthReport: public std::fstream
{
    Options &d_options;
    PolicyFile const &d_policyFile;

    std::ios::pos_type   d_startSize = 0;
    std::ios::pos_type   d_beginMail = 0;

    std::string  d_name;
    std::string  d_headerLine;

    public:
        StealthReport(Options &options, PolicyFile const &policyFile);
        ~StealthReport();
        
        StealthReport(StealthReport const &other) = delete;
        StealthReport &operator=(StealthReport const &other) = delete;

        void timestamp(char const *label, size_t nScans);
        void mail();
        void scanHeader();          // writes the integrity scan header,
                                    // initializes d_beginMail
    private:
        void rewind();              // prepare for reading
        void processMail();
        void sendMail();
        void refresh();             // set d_beginMail to the log's EOF pos.
        bool hasMail();             // true if there is info beyond
                                    // d_beginMail
};

#endif
