#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    int pow;
    struct node* next;
}node;
int poly = 0;
node* poly1, *poly2;
node* createlist(node* head);
void addition(node* head1, node* head2);
void display(node* head);

int main()
{
    /*try:
     *5x^3+4x^2+2x^1+3x^0
     *6x^2+1x^1+4x^0*/
    poly1 = createlist(poly1);
    poly2 = createlist(poly2);
    addition(poly1 , poly2);
    printf("\n");
    return 0;
}
node* createlist(node* head)
{
    int i, n, coeff, pow;
    node* newNode;
    node* temp;
    poly++;
    printf("How many terms you want in polynomial %d ?\n", poly);
    scanf(" %d", &n);
    
    for(i = 0 ; i < n ; i++)
    {
        printf("Enter Coeff: \n");
        scanf(" %d", &coeff);
        printf("Enter pow: \n");
        scanf("  %d", &pow);
        if(head != NULL)
        {
            newNode = (node*)malloc(sizeof(node));
            newNode->data = coeff;
            newNode->pow = pow;
            newNode->next = NULL;
            temp->next = newNode;
            temp = newNode;
            display(head);
        }
        if(head == NULL)
        {
            newNode = (node*)malloc(sizeof(node));
            newNode->data = coeff;
            newNode->pow = pow;
            newNode->next = NULL;
            head = newNode;
            temp = newNode;
            display(head);
        }
    }
    return head;
}
void addition(node* head1, node* head2)
{
    node* p1 = head1;
    node* p2 = head2;
    printf("Addition: ");
    while(p1 != NULL || p2 != NULL)
    {
        if(p1->pow > p2->pow)
        {
            printf("%dx^%d", p1->data, p1->pow);
            p1 = p1->next;
        }
        if(p2->pow > p1->pow)
        {
            printf("+ %dx^%d",p2->data,p2->pow);
            p2=p2->next;
        }
        if(p2->pow==p1->pow)
        {
            printf("+ %dx^%d",p1->data+p2->data,p2->pow);
            p2 = p2->next;
            p1 = p1->next;
        }else
        {
            printf("+%dx^%d", p1->data, p1->pow);
            printf("+ %dx^%d",p2->data,p2->pow);
            printf("\n");
            p1 = p1->next;
            p2=p2->next;
        }
        
    }
}
void display(node* head)
{
    node* temp;
    temp = head;
    printf("Polynomial %d is: ",poly);
    while(temp->next != NULL)
    {
        printf(" %dx^%d +",temp->data, temp->pow);
        temp = temp->next;
    }
    printf(" %dx^%d",temp->data, temp->pow);
    printf("\n");
}
