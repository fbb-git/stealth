    #include "pipe.ih"

    int Pipe::useForReading()
    {
        close(d_fd[WRITE]);
        return d_fd[READ];
    }

