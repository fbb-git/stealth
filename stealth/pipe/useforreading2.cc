    #include "pipe.ih"

    void Pipe::useForReadingFrom(int fd)
    {
        useForReading();
    
        redirect(d_fd[READ], fd);
        close(d_fd[READ]);
    }

