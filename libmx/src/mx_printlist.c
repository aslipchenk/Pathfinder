#include "libmx.h"

void mx_printlist(t_list *list) {
    t_list *temp = list;

    while (temp) {
        mx_printstr(temp->data);
        mx_printchar('\n');
        temp = temp->next;
    }
}
