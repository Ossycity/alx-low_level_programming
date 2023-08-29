#include "lists.h"

/**
 * free_listint_safe - frees a linked list, even if it contains a loop
 * @h: double pointer to the first node of the list
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *slow, *fast, *temp;

	if (!h || !*h)
		return (0);

	slow = *h;
	fast = *h;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) /* Loop detected */
		{
			slow = *h;

			/* Move slow and fast until they meet again */
			while (slow != fast)
			{
				temp = fast;
				while (fast->next != slow && fast->next != fast)
					fast = fast->next;
				if (fast->next == slow)
					break;
				slow = slow->next;
				fast = temp;
			}

			/* Free the looped portion */
			while (slow != fast->next)
			{
				temp = slow->next;
				free(slow);
				slow = temp;
				len++;
			}

			/* Free the remaining part of the list */
			while (slow != fast)
			{
				temp = slow->next;
				free(slow);
				slow = temp;
				len++;
			}

			free(fast); /* Free the last node */
			len++;
			*h = NULL;
			break;
		}
	}

	/* Free the rest of the list if no loop is detected */
	while (*h)
	{
		temp = (*h)->next;
		free(*h);
		*h = temp;
		len++;
	}

	return (len);
}
