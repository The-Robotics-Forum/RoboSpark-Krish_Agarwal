#include <stdio.h>
#include <stdlib.h>

struct node {
   int data; 
	
   struct node *leftChild;
   struct node *rightChild;
};

struct node *root = NULL;

//INSERATION OF ARRARY VALUE IN TREE

/*ALGORTHM
Step 1 − Recursively traverse left subtree.
Step 2 − Recursively traverse right subtree.
Step 3 − Visit root node.*/

void insert(int data) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   //if tree is empty
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;

      while(1) { 
         parent = current;
         if(data < parent->data) {
            current = current->leftChild;                
            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }  
         else {
            current = current->rightChild;
            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }            
   }
}

struct node* search(int data) {
   struct node *current = root;
   printf("Visiting elements: ");

   while(current->data != data) {
      if(current != NULL)
         printf("%d ",current->data); 
      if(current->data > data) {
         current = current->leftChild;
      }
      else {                
         current = current->rightChild;
      }
      if(current == NULL) {
         return NULL;
      }
   }
   return current;
}

//POST ORDER CODE...!
void post_order_traversal(struct node* root) {
   if(root != NULL) {
      post_order_traversal(root->leftChild);
      post_order_traversal(root->rightChild);
      printf("%d ", root->data);
   }
}

int main() {
   int i;
   //DELCLARATION OF ARRAY OF SIZE N
   int n;
   printf("Enter the size of ARRAY");
   scanf("%d",&n);
   int array[n],f;
   for(f=0;f<=n-1;f++){
       printf("Enter the elements of ARRAY");
       scanf("%d",&array[f]);
   }
   for(i = 0; i <=n-1; i++)
      insert(array[i]); //FUNCATION CALL FOR INSERTION IN TREE
    printf("Enter the number which you want to search in ARRAY");
   scanf("%d",&i);
   struct node * temp = search(i);
    if(temp != NULL) {
      printf("[%d] Element found.", temp->data);
      printf("\n");
   }else {
      printf("[ x ] Element not found (%d).\n", i);
   }
   printf("\nPost order traversal: ");
   post_order_traversal(root);       

   return 0;
}