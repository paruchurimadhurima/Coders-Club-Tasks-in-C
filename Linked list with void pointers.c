#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    void *data;
    struct node *next;
    void(*display_datatype)();
} node;
typedef struct  LLhead
{
    struct node *head;
    struct node *tail;
} LLhead;
void create_linkedlist(LLhead **LLhead)
{
    *LLhead = malloc(sizeof(LLhead));
    (*LLhead)->head = malloc(sizeof(node));
    (*LLhead)->head = NULL;
    (*LLhead)->tail = malloc(sizeof(node));
    (*LLhead)->tail = NULL;
}
void insert(LLhead **LLhead, void(*display_datatype)(void *data), void * data, size_t(*get_size)(void *data))
{

    size_t size = get_size(data);
    node *temp;
    temp = malloc(sizeof(node));
    temp->data = malloc(size);
    memcpy(temp->data, data, size);
    temp->display_datatype = display_datatype;
    temp->next = (*LLhead)->tail;
    (*LLhead)->tail = temp;
    if ((*LLhead)->head == NULL)
        (*LLhead)->head = (*LLhead)->tail;

}
void display_int(void *data)
{
    printf("%d\n", *(int *)data);
}
void display_float(void *data)
{
    printf("%lf\n", *(double *)data);
}
void display_char(void *data)
{
    printf("%c\n", *(char *)data);
}
void display_string(void *data)
{
    while (*(char *)data != '\0')
    {
        printf("%c", *(char *)data);
        data= (char *)data+1;
    }
    printf("\n");
}
void display(node *tail)
{
    if (tail == NULL)
        printf("List is empty\n");
    else
    {
        while (tail)
        {
            tail->display_datatype(tail->data);
            tail = tail->next;
        }
    }
}

size_t get_size_int(void *data)
{
    return sizeof(int);
}
size_t get_size_float(void *data)
{
    return sizeof(double);
}
size_t get_size_char(void *data)
{
    return sizeof(char);
}
size_t get_size_string(void *str)
{
    char *str1 = (char *)str;
    return strlen(str1) + 1;
}

void insert_int(LLhead **LLhead, int val)
{
    insert(&(*LLhead), display_int, (void *)&val, get_size_int);
}
void insert_float(LLhead **LLhead, double val)
{
    insert(&(*LLhead), display_float, (void *)&val, get_size_float);
}
void insert_string(LLhead **LLhead, char *str)
{
    insert(&(*LLhead), display_string, (void *)str, get_size_string);
}
void insert_char(LLhead **LLhead, char ch)
{
    insert(&(*LLhead), display_char, (void *)&ch, get_size_char);
}
int main()
{
    LLhead * LLhead;
    create_linkedlist(&LLhead);
    int i;
    int intnum = 0;
    for (i = 0; i<10; i++)
    {
        intnum++;
        insert_int(&LLhead, intnum);
    }
    char str[] = "madhurima";
    insert_string(&LLhead, str);
    char ch = 'p';
    insert_char(&LLhead, ch);
    double floatnum = 0.101;
    for (i = 0; i<10; i++)
    {
        floatnum++;
        insert_float(&LLhead, floatnum);
    }
    display(LLhead->tail);
    printf("Succeed\n");
    system("pause");
    return 0;
}
