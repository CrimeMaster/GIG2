#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    char data;
    struct node* prev;
    struct node* next;
}node;

node* newNode, *last = NULL;
void insert(char data);
void insertatEnd(char data);
void display();
void reverse();
void delete();
int main()
{
    insert('d');
    insert('l');
    insert('r');
    insert('o');
    insert('w');
    insert('+');
    insert('o');
    insert('l');
    insert('l');
    insert('e');
    insert('h');
    display();
    reverse();
    insertatEnd('!');
    display();
    return 0;
}
void insert(char data)
{
    node* temp;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    if(last == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        last = newNode;
        last->next = last;
    }
    else
        newNode->prev = last;
    newNode->next = last->next;
    last->next = newNode;
    temp = newNode->next;
    temp->prev = newNode;
}
void insertatEnd(char data)
{
    node* temp;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    if(last == NULL)
    {
        newNode->prev = newNode;
        newNode->next = newNode;
        last = newNode;
        last->next = last;
    }else
        newNode->prev = last;
    newNode->next = last->next;
    last->next = newNode;
    temp = newNode->next;
    temp->prev = newNode;
    newNode = last;
    
}
void delete()
{
    node* temp, *cur;
    if(last == NULL)
    {
        printf("The list is empty \n");
    }
    else
        temp = last->next;
    last->next = temp->next;
    cur = last->next;
    cur->prev = last;
    printf("Element deleted is %c\n",temp->data);
    free(temp);
}
void reverse()
{
    node* temp = last;
    if(last == NULL)
    {
        printf("list is Empty !");
    }
    else
        do
        {
            printf(" %c ", temp->data);
            temp = temp->prev;
        }while(temp != last);
    printf("\n");
}
void display()
{
    node* temp = last->next;
    if(last == NULL)
    {
        printf("List is Empty !");
    }
    else
        do
        {
            printf(" %c ", temp->data);
            temp = temp->next;
        }while(temp != last->next);
    printf("\n");
}
