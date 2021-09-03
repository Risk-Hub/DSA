#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *createlist(struct node *);
struct node *insertBefore(struct node *);
int main()
{
    start = createlist(start);
    insertBefore(start);
    return 0;
}
struct node *createlist(struct node *start)
{
    struct node *new_node, *ptr;
    int n, num;
    printf("\nEnter the number of nodes in the list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the data in node-%d: ", i + 1);
        scanf("%d", &num);
        new_node = (struct node *)malloc(sizeof(struct node));
        if (start == NULL)
        {
            new_node->next = NULL;
            new_node->data = num;
            new_node->prev = NULL;
            start = new_node;
        }
        else
        {
            new_node->data = num;
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
        }
    }
    return start;
}
struct node *insertBefore(struct node *start)
{
    struct node *new_node, *ptr;
    int n, val;
    printf("\nEnter the data to be inserted: ");
    scanf("%d", &n);
    printf("\nEnter the value before which the element has to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nOut of memory space");
        exit(0);
    }
    new_node->data = n;
    ptr = start;
    if (ptr->data == val)
    {
        new_node->next = start;
        start->prev = new_node;
        new_node->prev = NULL;
        start = new_node;
    }
    else
    {
        while (ptr->data != val)
        {
            ptr = ptr->next;
        }
        new_node->next = ptr;
        new_node->prev = ptr->prev;
        ptr->prev->next = new_node;
        ptr->prev = new_node;
    }
    ptr = start;
    printf("\nThe values in the list are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}