#include "policyfile.ih"

void PolicyFile::fixRelativeLocations()
{
    string const &base = d_use["BASE"];

    Util::absPath(base, d_use["REPORT"]);

    for (auto &line: d_command)
    {
            // [LOCAL] CHECK [LOG =] <logfile> [pathOffset] <command>
            // [LOCAL] NOTEST CHECK <logfile>  [pathOffset] <command>
            // NOTEST CHECK [LOG =] <logfile> [pathOffset] <command>

        if (s_log << line)
        {
            string logName = s_log[4];
            Pattern::Position pos = s_log.position(4);

            Util::absPath(base, logName);

            line.replace(pos.first, pos.second - pos.first, logName);
        }
    }
}





