#include <stdlib.h>
#include "custom_lists.h"

/**
 * custom_list_length - returns the number of elements in a custom linked list
 * @head: pointer to the custom_node_t list
 *
 * Return: number of elements in the custom list
 */
size_t custom_list_length(const custom_node_t *head)
{
    size_t count = 0;

    while (head)
    {
        count++;
        head = head->next;
    }

    return (count);
}
