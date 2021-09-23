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
struct node *display(struct node *);
int main()
{
    start = createlist(start);
    display(start);
    return 0;
}
struct node *createlist(struct node *start)
{
    int n;
    printf("\nEnter the number of nodes in the list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        struct node *new_node;
        int num;
        printf("\nEnter the data in node-%d: ", i + 1);
        scanf("%d", &num);
        if (start == NULL)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = num;
            new_node->next = new_node->prev = new_node;
            start = new_node;
        }

        else
        {
            struct node *last = (start)->prev;
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = num;
            new_node->next = start;
            (start)->prev = new_node;
            new_node->prev = last;
            last->next = new_node;
        }
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    printf("\nValues in the list are: ");
    while (ptr->next != start)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
}