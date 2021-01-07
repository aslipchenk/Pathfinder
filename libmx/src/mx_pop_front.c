#include "libmx.h"

void mx_pop_front(t_list **head) {
 t_list *del_front = NULL;

    if (head == NULL || *head == NULL)
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    }
    else {
        del_front = (*head)->next;
        free(*head);
        *head = del_front;
    }
}


