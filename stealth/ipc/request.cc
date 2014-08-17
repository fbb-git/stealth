#include "ipc.ih"

StealthEnums::Mode IPC::request()
{
    ifstream runFile;
    Exception::open(runFile, d_options.runFile());

    runFile.ignore(numeric_limits<int>::max(), '\n');

    runFile >> d_requestText;

    auto iter = s_request.find(d_requestText);

    return iter == s_request.end() ? Mode::UNKNOWN : iter->second;
}
