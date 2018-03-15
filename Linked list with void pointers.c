#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    void *data;
    struct node *next;
} node;
typedef struct note
{
    struct node *head ;
    struct node *tail ;
} note;
 
void insert(node **tail, const void * pointer, size_t size)
{
    node *temp;
    temp = malloc(sizeof(node));
    temp->data = malloc(size);
    memcpy(temp->data, pointer, size);
    temp->next = *tail;
    *tail = temp;
 
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
    if (tail == NULL)
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
    note note;
    note.head=NULL;
    note.tail=NULL;
    int intnum = 0;
    int i;
    for (i = 0; i<10; i++)
    {
        intnum++;
        insert(&note.tail, (const void *)&intnum, sizeof(intnum));
        if( note.head==NULL)
            note.head= note.tail;
    }
    display(display_int, note.tail);
    double floatnum = 0.101;
    note.tail = NULL, note.head = NULL;
    for (i = 0; i<10; i++)
    {
        floatnum++;
        insert(&note.tail, (const void *)&floatnum, sizeof(floatnum));
        if( note.head==NULL)
            note.head= note.tail;
    }
    display(display_float, note.tail);
    printf("Succeed\n");
    return 0;
}