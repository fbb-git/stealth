#include "pattern.h2"

namespace FBB
{

Pattern::~Pattern()
{
    regfree(&regex);
    delete subExpression;
}

}
