#include "lists.h"
#include <stdio.h>

int check_cycle(listint_t* list)
{
    listint_t* fast;
    listint_t* slow;

    fast = slow = list;
    while (fast && slow && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return (1);
    }
    return (0);
}
