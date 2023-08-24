#ifndef CUSTOM_LIST_H
#define CUSTOM_LIST_H

/**
 * struct custom_node_s - singly linked list node
 * @data: data - (malloc'ed string)
 * @length: length of the string
 * @next: points to the next node
 *
 * Description: Singly linked list node structure
 * for a custom project
 */
typedef struct custom_node_s
{
    char *data;
    unsigned int length;
    struct custom_node_s *next;
} custom_node_t;

size_t custom_list_print(const custom_node_t *head);
size_t custom_list_length(const custom_node_t *head);
custom_node_t *custom_list_add_node(custom_node_t **head, const char *data);
custom_node_t *custom_list_add_node_end(custom_node_t **head, const char *data);
void custom_list_free(custom_node_t *head);

#endif
