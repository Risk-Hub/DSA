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
struct node *insertEnd(struct node *);
int main()
{
    start = createlist(start);
    insertEnd(start);
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
        if (start == NULL)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = num;
            new_node->next = start;
            new_node->prev = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = num;
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
struct node *insertEnd(struct node *start)
{
    struct node *new_node, *ptr;
    int n;
    printf("\nEnter the data to be inserted at the end: ");
    scanf("%d", &n);
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nOut of memory space");
        exit(0);
    }
    new_node->data = n;
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = NULL;
    ptr = start;
    printf("\nThe values in the list are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}