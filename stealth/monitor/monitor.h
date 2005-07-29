#ifndef _INCLUDED_MONITOR_H_
#define _INCLUDED_MONITOR_H_

namespace FBB
{
    class Reporter;
    class Scanner;
    class ConfigSorter;


    class Monitor
    {
        enum Mode
        {
            ONCE,           // 0 single run 
            KEEP_ALIVE,     // 1 multiple runs
            TERMINATE,      // 2 through SIGTERM
            TERMINATED,     // 3 automatically following TERMINATE
            SUPPRESS,       // 4 through SIGUSR1 (SIGUSR2: back to normal)
            SUPPRESSED,     // 5 automatically following SUPPRESS
        };

        static Mode             s_mode;
        static bool             s_quit; // passed to Scanner::run() for
                                        // inspection         

        Scanner &d_scanner;
        ConfigSorter &d_sorter;
        Reporter &d_reporter;


        public:
            Monitor(ConfigSorter &sorter, Reporter &reporter, 
                    Scanner &scanner);

            void control();             // control the scanning process
            void mailReport();          // mail the report to the responsible
                                        // person

            static void handleProcessSignals(int signum);

        private:

            void        processMode();  // process the current mode

            void        setDelay();     // set delay interval matching the
                                        // current mode.
    };

}
#endif
