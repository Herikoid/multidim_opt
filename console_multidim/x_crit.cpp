#include "x_crit.h"

bool x_crit::check(sup_struct& s)
{
    if (abs(s.x - s.x_old) < eps || s.iter >= max_iter) {
        return false;
    }

    return true;
}
