#include "options.ih"

size_t Options::randomAddition() const
{
    return d_delayInterval ? 
                d_delayInterval * (random() / (RAND_MAX + 1.0))
            :
                0;
}
