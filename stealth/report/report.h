#ifndef REPORT_H_
#define REPORT_H_

#include <string>
#include <fstream>

class Options;
class PolicyFile;

class Report: public std::fstream
{
    std::string  d_name;

    Options &d_options;
    PolicyFile const &d_policyFile;

    std::ios::pos_type   d_startSize;
    std::ios::pos_type   d_beginMail;

    std::string  d_headerLine;

    public:
        Report(Options &options, PolicyFile const &policyFile);
        ~Report();
        
        Report(Report const &other) = delete;
        Report &operator=(Report const &other) = delete;

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

        std::ios::pos_type  endpos();
};

#endif

