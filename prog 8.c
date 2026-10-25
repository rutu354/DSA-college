#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *left;
   struct Node *right;
};

struct Node *createNode(int val)
{
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   newNode->data = val;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}

struct Node *insert(struct Node *root, int val)
{
   if (root == NULL)
   {
      return createNode(val);
   }
   if (val < root->data)
   {
      root->left = insert(root->left, val);
   }
   else if (val > root->data)
   {
      root->right = insert(root->right, val);
   }
   return root;
}

struct Node *search(struct Node *root, int key)
{
   if (root == NULL || root->data == key)
   {
      return root;
   }
   if (key < root->data)
   {
      return search(root->left, key);
   }
   return search(root->right, key);
}

void inorder(struct Node *root)
{
   if (root != NULL)
   {
      inorder(root->left);
      printf("%d ", root->data);
      inorder(root->right);
   }
}

void preorder(struct Node *root)
{
   if (root != NULL)
   {
      printf("%d ", root->data);
      preorder(root->left);
      preorder(root->right);
   }
}

void postorder(struct Node *root)
{
   if (root != NULL)
   {
      postorder(root->left);
      postorder(root->right);
      printf("%d ", root->data);
   }
}

int main()
{
   struct Node *root = NULL;
   int choice, val;
   while (1)
   {
      printf("\n1. Insert\n");
      printf("2. Search\n");
      printf("3. Inorder\n");
      printf("4. Preorder\n");
      printf("5. Postorder\n");
      printf("6. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch (choice)
      {
         case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            root = insert(root, val);
            break;
         case 2:
            printf("Enter value to search: ");
            scanf("%d", &val);
            if (search(root, val) != NULL)
            {
               printf("Found\n");
            }
            else
            {
               printf("Not found\n");
            }
            break;
         case 3:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;
         case 4:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
         case 5:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
         case 6:
            return 0;
         default:
            printf("Invalid choice\n");
      }
   }
   return 0;
}
