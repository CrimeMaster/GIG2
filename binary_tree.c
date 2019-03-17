#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;
node* root = NULL, *newNode;
node* createNode(int data)
{
    newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void insert();
void display();

int main()
{
    int data;
    /*create root*/
   /* root = createNode(1);
    root->left        = createNode(2);
    root->right       = createNode(3);
    root->left->left  = createNode(4);*/
    
    printf("Enter root of the tree\n");
    scanf(" %d", &data);
    root = createNode(data);
    
    display(root);
    getchar();
    
    return 0;
}
void insert(node* temp)
{
    char input;
    int data;
    printf("The leaf is %d\n",temp->data);
    printf("[a] insert Left [d] insert Right\n");
    scanf(" %c",&input);
    printf("Enter data: ");
    scanf(" %d",&data);
    if(input == 'a')
    {
        temp->left = createNode(data);
        display(root);
    }
    else if(input == 'd')
    {
        temp->right = createNode(data);
        display(root);
    }
    
}
void display(node* temp)
{
    char inp;
    int data;
    if(temp == root)
    {
        printf("root: %d\n",root->data);
    }
    printf("[a]left [d]right [w]root [s]insert\n");
    scanf(" %c",&inp);
    
    if(inp == 'a')
    {
        temp = temp->left;
        printf("data : %d\n",temp->data);
        display(temp);
    }
    else if(inp == 'd')
    {
        temp = temp->right;
        printf("data : %d\n",temp->data);
        display(temp);
    }
    else if(inp == 'w')
    {
        temp = root;
        display(temp);
    }
    else if(inp == 's')
    {
        insert(temp);
    }
    
}
