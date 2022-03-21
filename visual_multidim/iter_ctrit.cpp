#include "iter_ctrit.h"

void iter_ctrit::set_dist(int i)
{
    iter_dist = i;
}

bool iter_ctrit::check(sup_struct& s)
{
    if (s.iter - s.suc_iter >= iter_dist || s.iter >= max_iter) {
        return false;
    }

    return true;
}
