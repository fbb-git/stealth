    #include "pipe.ih"

    void Pipe::redirect(int d_fd, int alternateFd)
    {
        if (dup2(d_fd, alternateFd) < 0)
            throw Errno(1, "Pipe: redirection failed");
    }
