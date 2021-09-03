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
struct node *deleteBefore(struct node *);
int main()
{
    start = createlist(start);
    deleteBefore(start);
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
            new_node->prev = NULL;
            new_node->data = num;
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            new_node = (struct node *)malloc(sizeof(struct node));
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
struct node *deleteBefore(struct node *start)
{
    struct node *ptr, *temp;
    int val;
    printf("\nEnter the data before which the node has to be deleted: ");
    scanf("%d", &val);
    ptr = start;
    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    temp = ptr->prev;
    if (temp == start)
    {
        start = start->next;
        start->prev = NULL;
    }
    else
    {
        ptr->prev = temp->prev;
        temp->prev->next = ptr;
    }
    free(temp);
    ptr = start;
    printf("\nValues in the list are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}