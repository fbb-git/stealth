    #include "pipe.ih"

    int Pipe::useForWriting()
    {
        close(d_fd[READ]);
        return d_fd[WRITE];
    }

