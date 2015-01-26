template <typename Rep, typename Period>
std::cv_status Semaphore::wait_for(
                        std::chrono::duration<Rep, Period> const &relTime)
{
    std::unique_lock<std::mutex> lk(d_mutex);   // get the lock
    while (d_nAvailable == 0)
        if (d_condition.wait_for(lk, relTime) == std::cv_status::timeout)
            return std::cv_status::timeout;

    --d_nAvailable;
    return std::cv_status::no_timeout;
}
