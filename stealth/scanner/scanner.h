#ifndef _INCLUDED_SCANNER_H_
#define _INCLUDED_SCANNER_H_

#include <string>
#include <vector>
#include <iosfwd>
#include <sys/types.h>
#include <bobcat/process>

namespace FBB
{
    class Pattern;
    class Arg;
}

class ConfigSorter;
class Reporter;

class Scanner
{
    typedef std::vector<std::string>     StringVector;
    typedef StringVector::const_-iterator const_iterator;

    FBB::Arg       &d_arg;
    ConfigSorter   &d_sorter;
    Reporter       &d_reporter;
    FBB::Pattern   &d_firstWord;
    FBB::Process    d_sshFork;
    FBB::Process    d_shFork;
    std::string     d_sentinel;
    std::string     d_label;
    const_iterator  d_cmdIterator;
    bool            d_testExitValue;
    size_t          d_nScans;
    off_t           d_maxSize;
    std::string     d_maxSizeStr;
    bool            d_quit;
    StringVector    d_skipFiles;
    std::string     d_skipFilePath;
    size_t          d_diffPrefix;
    size_t          d_pathOffset;       // begin of the abs path if not
                                        // at the first / on a line
                                        // This may be used with CHECK

                                        // the abs path is at the end of 
                                        // the line. Any text may precede
                                        // it
    bool (Scanner::*d_skip)(std::string &absPath);

    static FBB::Pattern  s_firstWord;
    static FBB::Pattern  s_exitValue;

    public:
        Scanner(ConfigSorter &sorter, Reporter &reporter);
        size_t nScans() const
        {
            return d_nScans;
        }
        void preamble();
        void loadSkipFiles();
        void nScansReset();
                                    // run one series of tests
        void        run(volatile bool *done);    


        void killChildren();
        
    private:
                        // copy a textfile
        void        copy(FBB::Process &src, std::string const &fname);

                        // terminate or return 'false' if the retrieved 
                        // file's size exceeds d_max_size.
        bool        checkSize(std::string const &fname, off_t length);

                                    // executes a command, and compares
                                    // its output to previously
                                    // generated output. Returns true if
                                    // the outputs are identical
        bool        doCHECKcommand(FBB::Process &child);

                                    // executes a command, without
                                    // comparing its output to previously
                                    // generated output
        void        doPlainCommand(FBB::Process &child);

                                    // execute the command from d_sorter
        void        execute(std::string const &command);    

                                    // get a remote file
        void        get(std::string const &command);

                                    // get the trimmed path name from the 
                                    // output of a CHECK or comparable command
                                    // (empty if no path on orgLine)
        std::string getPath(std::string const &orgLine) const;

                                    // execute a local command
        void        local(std::string const &command);

                                    // start the nextCommand, including
                                    // echo $? to obtain the resultcode
        void        nextCommand(std::ostream &inserter, 
                                std::string const &command);

                                    // returns true if the contents of the
                                    // `current' logfile and `logfile'
                                    // don't differ.
        bool        noDifferences(std::string const &current,
                                  std::string const &logfile);

                                    // put a local file to the client
        void        put(std::string const &command);

                                    // construct put-dd command
        std::string putCommand(std::string const &source, 
                                std::string const &destination) const;

                                    // copy any file
        void        read(FBB::Process &src, std::string const &fname);

                                    // execute a remote command
        void        remote(std::string const &command);

                                    // return `true' if `word' was the 
                                    // first word. In that case, remove 
                                    // `word', and have d_firstWord match
                                    // what's beyond. 
                                    // Return false otherwise.
        bool        removeFirstWord(char const *word); 

                                    // see if there are any differences
                                    // between the output of the current
                                    // command and the output from the
                                    // previously run command
        bool        sameOutput(std::string const &logfile,
                               FBB::Process &extractor);

                                    // define the sentinel. Redefined
                                    // at each new run()
        void        setSentinel();

                                    // see if the exit value is 0
        void        testExitValue(std::string const &cmd,
                                  std::string const &exitStr);

                                    // wait for the sentinel and exitvalue
        void        waitForSentinel(FBB::Process &extractor);

                                    // write any file to the client
        void        write(std::string const &fname);

        void        removeLOG();    // remove LOG = from current command

                                    // true if filename not in d_skipFiles
        bool        skip(std::string &line);
        bool        skipDecision(std::string &line, 
                                 std::string const &skipLine) const;

                                    // always indicates "don't skip"
        bool        dontSkip(std::string &line);

                                    // fill the d_skipFiles vector and set
        void        setSkip();      // d_skip to &skipING

        static std::string fileName(std::string const &name);
        static std::string datetime();
        static void replace(std::string &str, char const *org,
                                         char const *replacement);
        static void add(std::string const &line, StringVector &skipFiles);
};

inline void Scanner::nScansReset()
{
    d_nScans = 0;
}

#endif
