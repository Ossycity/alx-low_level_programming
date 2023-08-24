#include <stdio.h>
#include "lists.h"

/**
 * custom_print_list - prints all elements of a custom linked list
 * @head: pointer to the custom_node_t list to print
 *
 * Return: the number of nodes printed
 */
size_t custom_print_list(const custom_node_t *head)
{
    size_t nodes_printed = 0;

    while (head)
    {
        if (!head->data)
            printf("[0] (nil)\n");
        else
            printf("[%u] %s\n", head->length, head->data);

        head = head->next;
        nodes_printed++;
    }

    return (nodes_printed);
}
