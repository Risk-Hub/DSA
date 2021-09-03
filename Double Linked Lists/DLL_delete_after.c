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
struct node *deleteAfter(struct node *);
int main()
{
    start = createlist(start);
    deleteAfter(start);
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
            new_node->prev = NULL;
            new_node->next = NULL;
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
struct node *deleteAfter(struct node *start)
{
    struct node *ptr, *temp;
    ptr = start;
    int val;
    printf("\nEnter the data after which the node has to be deleted: ");
    scanf("%d", &val);
    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    if (temp->next == NULL)
    {
        ptr->next = NULL;
    }
    else
    {
        temp->next->prev = ptr;
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