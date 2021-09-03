#include <stdio.h>
#include <stdlib.h>
struct node
{
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
}
struct node *createlist(struct node *start)
{
    struct node *new_node, *ptr;
    int n;
    printf("\nEnter the number of nodes in the list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the value in node-%d: ", i + 1);
        scanf("%d", &new_node->data);
        if (start == NULL)
        {
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
        }
    }
    return start;
}
struct node *insertBefore(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\nEnter the data to be inserted: ");
    scanf("%d", &num);
    printf("\nEnter the value before which the data is to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nOut of memory space");
        exit(0);
    }
    new_node->data = num;
    ptr = start;
    if (ptr->data == val)
    {
        new_node->next = start;
        start = new_node;
    }
    else
    {
        while (ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = new_node;
        new_node->next = ptr;
    }
    ptr = start;
    printf("\nValues in the list are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}