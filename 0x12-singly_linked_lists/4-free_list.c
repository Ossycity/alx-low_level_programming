#include <stdlib.h>
#include "custom_lists.h"

/**
 * custom_free_list - frees a custom linked list
 * @head: custom_node_t list to be freed
 */
void custom_free_list(custom_node_t *head)
{
    custom_node_t *temp;

    while (head)
    {
        temp = head->next;
        free(head->data);
        free(head);
        head = temp;
    }
}
