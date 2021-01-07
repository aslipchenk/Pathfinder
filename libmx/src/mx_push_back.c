#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *new_list = mx_create_node(data);
    t_list *temp = *list;

    if (*list == NULL || list == NULL) {
        *list = new_list;
        return;
    }

    while (temp->next)
        temp = temp->next;
    temp->next = new_list;
}
