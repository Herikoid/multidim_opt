#include "f_crit.h"

bool f_crit::check(sup_struct& s)
{
    if (abs(s.f - s.f_old) < eps || s.iter >= max_iter) {
        return false;
    }

    return true;
}
