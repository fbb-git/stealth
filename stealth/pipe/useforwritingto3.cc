    #include "pipe.ih"

    void Pipe::useForWritingTo(int fd)
    {
        useForWritingTo(&fd, 1);
    }

