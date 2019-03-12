#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    int time;
    struct node *next;
}node;
int n, i;
node *newNode, *head= NULL;
void Creatlist(int n);
void display();
void sort();
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("How many Processes? \n");
    scanf("%d",&n);
    Creatlist(n);
    printf("First Come First Serve\n");
    display();
    sort();
    printf("Shortest Time First \n");
    display();
    
    
    return 0;
}
void Creatlist(n)
{
    node *temp;
    if(head == NULL)//if list is empty
    {
        newNode = (node*)malloc(sizeof(node));
        printf("Enter the burst time for p[%d]: \n",i+1);
        scanf("%d", &(newNode->data));
        newNode->time = i;
        newNode->next = NULL;
        head = newNode;
        temp = newNode;
    }
    for(i = 1 ; i < n ; i++)
    {
        newNode =  malloc(sizeof(node));
        printf("Enter the burst time for p[%d]: \n",i+1);
        scanf("%d", &(newNode->data));
        newNode->time = i;
        temp->next = newNode;
        newNode->next = NULL;
        temp = newNode;
    }
}
void sort()
{
    node* i;
    node* j;
    int  temp;
    
    
    
    for(i = head ; i->next != NULL ; i=i->next)
    {
        for(j = i->next ; j != NULL ; j=j->next)
        {
            if(i->data > j->data)
            {
                temp  = (int)i->data;
                i->data = j->data;
                j->data = temp;
                temp = i->time;
                i->time = j->time;
                j->time = temp;
            }
        }
    }
}
void display()
{
    struct node* temp = head;
    if(head == NULL)
        printf("list is empty\n");
    else
        printf("Process\tBurst time\tArrival Time\n");
        while(temp != NULL)
        {
            printf("p[%d]\t\t%d\t\t%d\n" ,temp->time+1,temp->data, temp->time);
            temp = temp -> next;
        }
}
