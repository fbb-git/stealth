
template <typename Rep, typename Period>  // wait for duration timeunits
void Semaphore::wait_for(chrono::duration<Rep, Period> const &relTime)
{
    unique_lock<timed_mutex> lk(d_mutex);   // get the lock
    while (d_nAvailable == 0)
        d_condition.wait(lk);   // internally releases the lock
                                // and waits, on exit
                                // acquires the lock again
    --d_nAvailable;              // dec. semaphore
}
