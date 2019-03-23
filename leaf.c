#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node* left;
  struct node* right;
}node;
node* root = NULL;
int leafs;
node* newNode(int data)
{
  node* temp = (node*)malloc(sizeof(node));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;

}
node* insert(node* node, int data)
{
  if(node == NULL)
    {
      return newNode(data);
    }
  else if(data < node->data)
      {
	node->left = insert(node->left, data); 
      }
  else if(data > node->data)
    {
      node->right = insert(node->right, data);
    }
  return node;

}
void display(node* node)
{
  char input;
  if(node == root)
    {
      printf("Root is %d\n", node->data);
    }
  else
    printf("Node is %d: \n", node->data);
  printf("[a] turn left [d] turn right \n");
  scanf(" %c", &input);
    if(input == 'a')
      {
	display(node->left);
      }
    else if(input == 'd')
      {
	display(node->right);
      }
  return;
}
 int getLeafCount(struct node* node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right==NULL)
    {
        printf(" %d is leaf\n", node->data);
        return 1;
    }
    else
        return getLeafCount(node->left)+
        getLeafCount(node->right);
}
int main()
{
  root = insert(root, 8);
  insert(root, 3);
  insert(root, 10);
  insert(root, 1);
  insert(root, 6);
  insert(root, 4);
  insert(root, 7);
  insert(root, 14);
  insert(root, 13);
  //display(root);
  //isleaf(root);
  printf("Total number of leaf is %d\n", getLeafCount(root));
  return 0;
}
