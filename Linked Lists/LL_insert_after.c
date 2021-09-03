#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *createlist(struct node *);
struct node *insertAfter(struct node *);
int main()
{
    start = createlist(start);
    insertAfter(start);
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
struct node *insertAfter(struct node *start)
{
    struct node *ptr, *new_node, *postptr;
    int n, val;
    printf("\nEnter the data to be inserted: ");
    scanf("%d", &n);
    printf("\nEnter the value after which the data is to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nOut of memory space");
        exit(0);
    }
    new_node->data = n;
    ptr = start;
    postptr = ptr->next;
    while (ptr->data != val)
    {
        ptr = ptr->next;
        postptr = postptr->next;
    }
    ptr->next = new_node;
    new_node->next = postptr;
    postptr = start;
    printf("\nValues in the list are: ");
    while (postptr != NULL)
    {
        printf("%d ", postptr->data);
        postptr = postptr->next;
    }
}