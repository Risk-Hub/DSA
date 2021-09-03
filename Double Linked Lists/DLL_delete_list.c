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
struct node *deleteList(struct node *);
int main()
{
    start = createlist(start);
    deleteList(start);
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
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            new_node->data = num;
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
        }
    }
    return start;
}
struct node *deleteList(struct node *start)
{
    struct node *ptr;
    int i = 1;
    ptr = start;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        ptr->prev = NULL;
        printf("\nNode-%d is now deleted", i);
        free(ptr);
        i++;
    }
}