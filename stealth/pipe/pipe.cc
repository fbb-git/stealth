    #include "pipe.ih"

    Pipe::Pipe()
    {
        if (pipe(d_fd))
            throw Errno(1, "Pipe::Pipe(): pipe() failed");
    }

