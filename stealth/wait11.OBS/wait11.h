#ifndef INCLUDED_WAIT11_
#define INCLUDED_WAIT11_

#include <mutex>
#include <condition_variable>

class Wait11
{
    bool                    d_signaled = false;
    std::mutex              d_mutex;
    std::condition_variable d_condition;

    public:
        void waitSignal(bool doM2 = true);  // wait for a signal to arrive
        void waitFor(size_t seconds, bool doM2 = true);

        void notify();

        bool signaled() const;

    private:
};

inline bool Wait11::signaled() const
{
    return d_signaled;
}
        
#endif
