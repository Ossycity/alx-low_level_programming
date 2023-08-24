#include <stdlib.h>
#include <string.h>
#include "custom_lists.h"

/**
 * custom_add_node - adds a new node at the beginning of a custom linked list
 * @head: double pointer to the custom_node_t list
 * @data: new string to add in the node
 *
 * Return: the address of the new element, or NULL if it fails
 */
custom_node_t *custom_add_node(custom_node_t **head, const char *data)
{
    custom_node_t *new_node;
    unsigned int length = 0;

    while (data[length])
        length++;

    new_node = malloc(sizeof(custom_node_t));
    if (!new_node)
        return (NULL);

    new_node->data = strdup(data);
    new_node->length = length;
    new_node->next = (*head);
    (*head) = new_node;

    return (*head);
}
