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

void insert(node **tail,void(*display_datatype)(node *tail), void * pointer,int (*function)(void *ptr))
{

    int size=function(pointer);
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
void display_char(node *tail)
{
    printf("%c\n", *(char *)tail->data);
}
void display_string(node *tail)
{
    char *str=(char *)tail->data;
    while(*str!='\0')
    {
        printf("%c", *str);
        str++;
    }
    printf("\n");
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
int get_size_string(void *str)
{
    char *str1=(char *)str;
    return strlen(str1)+1;
}

void insert_int(node **node,int val)
{
    insert(&(*node),display_int, (void *)&val,get_size_int);
}
void insert_float(node **node,double val)
{
    insert(&(*node),display_float, (void *)&val,get_size_float);
}
void insert_string(node **node,char *str)
{
    insert(&(*node),display_string, (void *)str,get_size_string);
}
void insert_char(node **node,char ch)
{
    insert(&(*node),display_char, (void *)&ch,get_size_char);
}
int main()
{
    note *note;
    note=malloc(sizeof(note));
    (*note).head=malloc(sizeof(node));
    (*note).head=NULL;
    (*note).tail=malloc(sizeof(node));
    (*note).tail=NULL;
    int i;
    int intnum = 0;
    for (i = 0; i<10; i++)
    {
        intnum++;
        insert_int(&(*note).tail,intnum);
        if( (*note).head==NULL)
            (*note).head= (*note).tail;
    }
    char str[]="madhurima";
    insert_string(&(*note).tail,str);
    char ch='p';
    insert_char(&(*note).tail,ch);
    double floatnum = 0.101;
    for (i = 0; i<10; i++)
    {
        floatnum++;
        insert_float(&(*note).tail,floatnum);
        if( (*note).head==NULL)
            (*note).head= (*note).tail;
    }
    display( (*note).tail);
    printf("Succeed\n");
    return 0;
}
