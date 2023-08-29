#include "lists.h"

/**
 * find_listint_loop - Detects a loop within a linked list.
 * @head: A pointer to the head of the linked list.
 *
 * Return: A pointer to the node where the loop starts, or NULL if no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow = head; // Initialize a slow pointer.
    listint_t *fast = head; // Initialize a fast pointer.

    // Check if the list is empty.
    if (!head)
        return (NULL);

    // Detect a loop using Floyd's Cycle Detection Algorithm.
    while (slow && fast && fast->next)
    {
        fast = fast->next->next; // Move fast pointer by two steps.
        slow = slow->next;      // Move slow pointer by one step.

        // If fast meets slow, a loop is detected.
        if (fast == slow)
        {
            slow = head; // Reset slow to the head of the list.

            // Move both pointers at the same pace until they meet again.
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return (fast); // Return the starting point of the loop.
        }
    }

    return (NULL); // No loop detected.
}
