#include <stdlib.h>
#include <string.h>
#include "custom_lists.h"

/**
 * custom_add_node_end - adds a new node at the end of a custom linked list
 * @head: double pointer to the custom_node_t list
 * @data: string to put in the new node
 *
 * Return: address of the new element, or NULL if it fails
 */
custom_node_t *custom_add_node_end(custom_node_t **head, const char *data)
{
    custom_node_t *new_node;
    custom_node_t *temp = *head;
    unsigned int length = 0;

    while (data[length])
        length++;

    new_node = malloc(sizeof(custom_node_t));
    if (!new_node)
        return (NULL);

    new_node->data = strdup(data);
    new_node->length = length;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    while (temp->next)
        temp = temp->next;

    temp->next = new_node;

    return (new_node);
}
