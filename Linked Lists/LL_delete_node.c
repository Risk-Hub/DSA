#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *createlist(struct node *);
struct node *deleteBeg(struct node *);
struct node *deleteNode(struct node *);
int main()
{
    start = createlist(start);
    deleteNode(start);
}
struct node *createlist(struct node *start)
{
    struct node *ptr, *new_node;
    int n, num;
    printf("\nEnter the number of nodes in the list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the value in node-%d: ", i + 1);
        scanf("%d", &num);
        new_node->data = num;
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
struct node *deleteBeg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}
struct node *deleteNode(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\nEnter the value in the node to be deleted: ");
    scanf("%d", &val);
    ptr = start;
    if (ptr->data == val)
    {
        start = deleteBeg(start);
        ptr = start;
        printf("\nValues in the list are: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    else
    {
        while (ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        ptr = start;
        printf("\nValues in the list are: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}