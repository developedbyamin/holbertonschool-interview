#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int list_size(listint_t* h)
{
    listint_t* current;
    unsigned int n;

    current = h;
    n = 0;
    while (current != NULL)
    {
        current = current->next;
        n++;
    }

    return (n);
}

listint_t* get(listint_t* head, int num)
{
    listint_t* current;

    current = head;
    while (current != NULL && num != 0)
    {
        current = current->next;
        num--;
    }
    return current;
}
void reverse(listint_t** head)
{
    listint_t* prev = NULL;
    listint_t* current = *head;
    listint_t* next = NULL;
    while (current != NULL) {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }
    *head = prev;
}
int is_palindrome(listint_t** head)
{
    int size = list_size(*head) / 2;
    listint_t* center = get(*head, size);
    listint_t* h;
    int i;
    
    h = *head;
    reverse(&center);

    for (i = 0; i < size;i++)
    {
        if (h->n == center->n)
        {
            h = h->next;
            center = center->next;
        }
        else
            return 0;
    }
    return 1;
}