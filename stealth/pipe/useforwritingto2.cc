    #include "pipe.ih"

    void Pipe::useForWritingTo(int const *fd, unsigned n)
    {
        useForWriting();
    
        for (unsigned idx = 0; idx < n; idx++)
            redirect(d_fd[WRITE], fd[idx]);

        close(d_fd[WRITE]);
    }
