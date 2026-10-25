#include <stdio.h>
#include <stdlib.h>

struct StackNode
{
   int data;
   struct StackNode *next;
};

struct QueueNode
{
   int data;
   struct QueueNode *next;
};

struct StackNode *top = NULL;
struct QueueNode *front = NULL;
struct QueueNode *rear = NULL;

void stack_push(int val)
{
   struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
   if (newNode == NULL)
   {
      printf("Memory allocation failed\n");
      return;
   }
   newNode->data = val;
   newNode->next = top;
   top = newNode;
   printf("%d pushed to stack\n", val);
}

void stack_pop()
{
   struct StackNode *temp;
   if (top == NULL)
   {
      printf("Stack is empty\n");
      return;
   }
   temp = top;
   printf("Popped element: %d\n", temp->data);
   top = top->next;
   free(temp);
}

void stack_display()
{
   struct StackNode *temp;
   if (top == NULL)
   {
      printf("Stack is empty\n");
      return;
   }
   printf("Stack elements:\n");
   temp = top;
   while (temp != NULL)
   {
      printf("%d\n", temp->data);
      temp = temp->next;
   }
}

void queue_enqueue(int val)
{
   struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
   if (newNode == NULL)
   {
      printf("Memory allocation failed\n");
      return;
   }
   newNode->data = val;
   newNode->next = NULL;
   if (rear == NULL)
   {
      front = rear = newNode;
   }
   else
   {
      rear->next = newNode;
      rear = newNode;
   }
   printf("%d enqueued to queue\n", val);
}

void queue_dequeue()
{
   struct QueueNode *temp;
   if (front == NULL)
   {
      printf("Queue is empty\n");
      return;
   }
   temp = front;
   printf("Dequeued element: %d\n", temp->data);
   front = front->next;
   if (front == NULL)
   {
      rear = NULL;
   }
   free(temp);
}

void queue_display()
{
   struct QueueNode *temp;
   if (front == NULL)
   {
      printf("Queue is empty\n");
      return;
   }
   printf("Queue elements: ");
   temp = front;
   while (temp != NULL)
   {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

int main()
{
   int choice, val;
   while (1)
   {
      printf("\n1. Stack Push\n");
      printf("2. Stack Pop\n");
      printf("3. Stack Display\n");
      printf("4. Queue Enqueue\n");
      printf("5. Queue Dequeue\n");
      printf("6. Queue Display\n");
      printf("7. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch (choice)
      {
         case 1:
            printf("Enter value to push: ");
            scanf("%d", &val);
            stack_push(val);
            break;
         case 2:
            stack_pop();
            break;
         case 3:
            stack_display();
            break;
         case 4:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            queue_enqueue(val);
            break;
         case 5:
            queue_dequeue();
            break;
         case 6:
            queue_display();
            break;
         case 7:
            return 0;
         default:
            printf("Invalid choice\n");
      }
   }
   return 0;
}
