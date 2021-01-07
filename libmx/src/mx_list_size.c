#include "libmx.h"

int mx_list_size(t_list *list) {
    t_list *pop = list;
    int count = 0;

    if (!list)
        return 0;
    while (pop) {
        pop = pop->next;
        count++;
    }
    return count;
}
