#include "grad_crit.h"

bool grad_crit::check(sup_struct& s)
{
    if (abs(s.gradient) < eps || s.iter >= max_iter) {
        return false;
    }

    return true;
}
