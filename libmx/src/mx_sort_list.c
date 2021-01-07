#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool(*cmp)(void *, void *)) {
    t_list *new_list = lst;
    int list_size = mx_list_size(lst);
    void *temp;

    for (int i = 0; i < list_size; i++) {
        new_list = lst;
        for (int j = 0; j < list_size - i - 1; j++) {
            if (cmp(new_list->data, new_list->next->data)) {
                temp = new_list->next->data;
                new_list->next->data = new_list->data;
                new_list->data = temp;
            }
            new_list = new_list->next;
        }
    }
    return lst;
}

