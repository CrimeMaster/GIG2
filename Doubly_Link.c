#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char data;
    struct node *prev;
    struct node *next;
}node;
node *newNode , *head = NULL;
void create();
void insertatBeg(char n);
void insertatMid(char n);
void insertatEnd(char n);

void delete();
void deleteatMid(char y);
void deleteatEnd();

void display();
int main(int argc, const char * argv[]) {
    // insert code here...
    int inp, n, i;
    char a;
        while(1)
        {
            printf("[1] Create [2] delete [3] display \n");
            printf("[4] insertatBeg [5] insertatMid [6] insertatEnd\n" );
            printf("[7] deleteatMid [8] deleteatEnd\n");
            scanf("%d",&inp);
            switch (inp) {
                case 1:
                    printf("How many nodes ?");
                    scanf("%d", &n);
                    for(i = 0 ; i < n ; i++)
                    {
                        create();
                    }
                    break;
                case 2:
                    delete();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    printf("Enter a character to be inserted \n");
                    scanf("%c ", &a);
                    insertatBeg(a);
                    break;
                case 5:
                    printf("Where should the character be inserted? \n");
                    scanf(" %c", &a);
                    insertatMid(a);
                    break;
                case 6:
                    printf("Enter a character to be inserted \n");
                    scanf("%c ", &a);
                    insertatEnd(a);
                    break;
                case 7:
                    printf("Enter a character to be deleted \n");
                    scanf(" %c", &a);
                    deleteatMid(a);
                    break;
                case 8:
                    deleteatEnd();
                    break;
                default:
                    
                    break;
            }
            
        }
  
    return 0;
}
void create()
{
    char n;
    if(head == NULL)
    {
        printf("Enter character: ");
        scanf(" %c",&n);
        newNode = (node*)malloc(sizeof(node));
        newNode->data = n;
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        printf("Enter character: ");
        scanf(" %c",&n);
        newNode = (node*)malloc(sizeof(node));
        newNode->data = n;
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}
void insertatBeg(char n)
{
    newNode = (node*)malloc(sizeof(node));
    newNode->data = n;
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void insertatMid(char n)
{
    node *temp = head, *temp2;
    while(temp->data != n)
        temp = temp->next;
    printf("Enter the data to be inserted \n");
    scanf(" %c",&n);
    temp2 = temp->next;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = n;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = temp2;
    
}
void insertatEnd(char n)
{
    node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = n;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
}
void delete()
{
    node* temp = head;
    if(temp == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    else
    head = temp->next;
    printf("deleted node is %c\n",temp->data);
    free(temp);
}
void deleteatMid(char y)
{
    node* temp = head, *temp2, *temp3;
    while(temp->data != y)
        temp = temp->next;
    printf("Deleted node is %c\n", temp->data);
    temp2 = temp->prev;
    temp3 = temp->next;
    temp2->next = temp3;
    temp3->prev = temp2;
    free(temp);
}
void deleteatEnd()
{
    node* temp = head,*temp2;
    while(temp->next != NULL)
        temp = temp->next;
    printf("Deleted node is %c\n", temp->data);
    temp2= temp->prev;
    temp2->next= NULL;
    free(temp);
}
void display()
{
    node* temp = head;
    if(temp == NULL)
    {
        printf("List is Empty \n");
    }
    else
        printf("head->");
        while(temp != NULL)
        {
            printf("<-%c->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
}
