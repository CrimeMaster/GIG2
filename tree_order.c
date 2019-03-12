#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *left, *right;
}node;
void display();
node* newNode (int item)
{
    node* temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
  if(root != NULL)
    {
      printf("%d\n", root->key);
      preorder(root->left);
      preorder(root->right);
    }
}
void postorder(struct node *root)
{
  if(root != NULL)
    {
      postorder(root->left);
      postorder(root->right);
      printf("%d\n",root->key);
    }

}
 node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
    {
       // printf("Newode is create of key : %d\n", key);
            return newNode(key);
    }
    
    /* Otherwise, recur down the tree */
    if (key < node->key)
    {
      //  printf("Newode is inserted in left->%d of key : %d\n",node->key, key);
        node->left  = insert(node->left, key);
    }
    else if (key > node->key)
    {
       // printf("Newode is inserted in right->%d of key : %d\n",node->key, key);
        node->right = insert(node->right, key);
    }
    
    /* return the (unchanged) node pointer */
    return node;
}
// Driver Program to test above functions
struct node *root = NULL;
int main()
{
    /* Let us create following BST
        50
     /     \
   30      70
  /  \    /  \
20   40  60   80 */
    
    root = insert(root, 45);
    insert(root, 25);
    insert(root, 55);
    insert(root, 65);
    insert(root, 15);
    insert(root, 35);
    insert(root, 5);
    insert(root, 77);
    insert(root, 88);
    
    printf("Inorder list\n");
    inorder(root);
    printf("Preorder list\n");
    preorder(root);
    printf("postorder list\n");
    postorder(root);
    //display(root);
    
    return 0;
}
void display(node* temp)
{
    char op=0;
    if(temp == root)
    printf("root is %d\n",root->key);
    
    while(temp != NULL)
    {
        printf("traverse left[a] traverse[d]\n");
        scanf(" %c", &op);
        if(op == 'a')
        {
                temp = temp->left;
                printf("%d\n",temp->key);       
        }
        else if(op == 'd')
            {
                temp = temp->right;
                printf("%d\n",temp->key);
               
            }
    }
}
