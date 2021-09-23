#include <stdio.h>
#include <stdlib.h>
struct node
{
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
    struct node *new_node, *ptr;
    int num, n;
    printf("\nEnter the number of nodes in the list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the data in node-%d: ", i + 1);
        scanf("%d", &num);
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL)
        {
            start = (struct node *)malloc(sizeof(struct node));
            start->data = n;
            start->next = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
        }
        new_node->next = NULL;
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    printf("\nValue in the header node: %d", start->data);
    ptr = start->next;
    printf("\nValues in the list are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}