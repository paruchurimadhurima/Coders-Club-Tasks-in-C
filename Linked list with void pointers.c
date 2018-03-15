#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    void *data;
    struct node *next;
} node;
struct node *head = NULL;
struct node *tail = NULL;
void insert(node **head, node **tail, const void * pointer, size_t size)
{
    if (*head == NULL)
    {
        *head = malloc(sizeof(node));
        (*head)->data = malloc(size);
        memcpy((*head)->data, pointer, size);
        (*head)->next = NULL;
        *tail = *head;
    }
    else
    {
        node *temp;
        temp = malloc(sizeof(node));
        temp->data = malloc(size);
        memcpy(temp->data, pointer, size);
        temp->next = *tail;
        (*tail) = temp;
 
    }
}
void display_int(node *tail)
{
    printf("%d\n", *(int *)tail->data);
}
void display_float(node *tail)
{
    printf("%lf\n", *(double *)tail->data);
}
void display(void(*display_datatype)(node *tail), node *tail)
{
    if (head == NULL)
        printf("List is empty\n");
    else
    {
        while (tail)
        {
            display_datatype(tail);
            tail = tail->next;
        }
    }
}
int main()
{
    int intnum = 0;
    int i;
    for (i = 0; i<10; i++)
    {
        intnum++;
        insert(&head, &tail, (const void *)&intnum, sizeof(intnum));
    }
    display(display_int, tail);
    double floatnum = 0.101;
    tail = NULL, head = NULL;
    for (i = 0; i<10; i++)
    {
        floatnum++;
        insert(&head, &tail, (const void *)&floatnum, sizeof(floatnum));
    }
    display(display_float, tail);
    printf("Succeed\n");
    return 0;
}