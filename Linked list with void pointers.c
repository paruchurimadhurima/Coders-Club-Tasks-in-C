#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    void *data;
    struct node *next;
    int (*funptr)();
} node;
typedef struct note
{
    struct node *head ;
    struct node *tail ;
} note;

void insert(node **tail,void(*display_datatype)(node *tail), const void * pointer, size_t size)
{
    node *temp;
    temp = malloc(sizeof(node));
    temp->data = malloc(size);
    memcpy(temp->data, pointer, size);
    temp->funptr =display_datatype;
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
void display_string(node *tail)
{
    printf("%c\n", *(char *)tail->data);
}
void display( node *tail)
{
    if (tail == NULL)
        printf("List is empty\n");
    else
    {
        while (tail)
        {
            tail->funptr(tail);
            tail = tail->next;
        }
    }
}

int get_size_int(int x)
{
    return sizeof(int);
}
int get_size_float(double x)
{
    return sizeof(double);
}
int get_size_char(char x)
{
    return sizeof(char);
}
int get_size(int (*function)(void *ptr), void *ptr)
{
    return function(ptr);
}
int main()
{
    note note;
    note.head=NULL;
    note.tail=NULL;
    int i;
    int intnum = 0;
    for (i = 0; i<10; i++)
    {
        intnum++;
        insert(&note.tail,display_int, (const void *)&intnum,get_size(get_size_int,(void *)&intnum));
        if( note.head==NULL)
            note.head= note.tail;
    }
    display( note.tail);
    double floatnum = 0.101;
    note.tail = NULL, note.head = NULL;
    for (i = 0; i<10; i++)
    {
        floatnum++;
        insert(&note.tail,display_float, (const void *)&floatnum,get_size(get_size_float,(void *)&floatnum));
        if( note.head==NULL)
            note.head= note.tail;
    }
    display( note.tail);
    printf("Succeed\n");
    return 0;
}
