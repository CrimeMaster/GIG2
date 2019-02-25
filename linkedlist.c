#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
}
  *newNode , *head = NULL;
void createlist(int n);
void insertatbeg();
void display();
int main()
{
  createlist(3);
  display();
  insertatbeg();
  display();
 
   

  return 0;
}
void createlist(int n)
{
  int i , data;
  /*if(head == NULL)
    {
      newNode = (struct node*)malloc(sizeof(struct node));
      printf("Enter the data\n");
      scanf("%d",&data);
      newNode->data = data;
      newNode->next = NULL;
      head = newNode;
      }else*/
    for(i = 0 ; i< n; i++)
      {
	newNode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data \n");
	scanf("%d",&data);
	newNode->data = data;
	newNode->next = head;
	head = newNode;

      }
  
}
void insertatbeg()
{
  int data;
      newNode = (struct node*)malloc(sizeof(struct node));
      printf("Enter the data at begining \n");
      scanf("%d",&data);
      newNode->data = data;
      newNode->next = head;
      head = newNode;
      free(head);
}
void display()
{
  struct node* temp;
  if(head== NULL)
    printf("List is empty\n");
  else
    {
      temp = head;
      while(temp != NULL)
	{
	  printf("%d->",temp->data);
	  temp = temp->next;
	}
      printf("NULL\n");
    }
}
