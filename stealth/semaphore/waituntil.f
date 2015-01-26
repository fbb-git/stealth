template <typename Clock, typename Duration>  // wait until abs. time
std::cv_status Semaphore::wait_until(chrono::time_point<Clock, Duration> 
                                     const &absTime) 
{
    std::unique_lock<std::mutex> lk(d_mutex);   // get the lock
    while (d_nAvailable == 0)
        if (d_condition.wait_until(lk, absTime) == std::cv_status::timeout)
            return std::cv_status::timeout;

    --d_nAvailable;
    return std::cv_status::no_timeout;
}
