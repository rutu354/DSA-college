#include <stdio.h>
#define MAX 50

int stack[MAX];
int top = -1;

int queue[MAX];
int front = -1;
int rear = -1;

void stack_push(int item)
{
   if (top >= MAX - 1)
   {
      printf("Stack is full\n");
      return;
   }
   top++;
   stack[top] = item;
   printf("%d pushed to stack\n", item);
}

void stack_pop()
{
   if (top < 0)
   {
      printf("Stack is empty\n");
      return;
   }
   printf("Popped element: %d\n", stack[top]);
   top--;
}

void stack_display()
{
   int i;
   if (top < 0)
   {
      printf("Stack is empty\n");
      return;
   }
   printf("Stack elements:\n");
   for (i = top; i >= 0; i--)
   {
      printf("%d\n", stack[i]);
   }
}

void queue_enqueue(int item)
{
   if (rear >= MAX - 1)
   {
      printf("Queue is full\n");
      return;
   }
   if (front == -1)
   {
      front = 0;
   }
   rear++;
   queue[rear] = item;
   printf("%d enqueued to queue\n", item);
}

void queue_dequeue()
{
   if (front == -1 || front > rear)
   {
      printf("Queue is empty\n");
      return;
   }
   printf("Dequeued element: %d\n", queue[front]);
   front++;
   if (front > rear)
   {
      front = -1;
      rear = -1;
   }
}

void queue_display()
{
   int i;
   if (front == -1 || front > rear)
   {
      printf("Queue is empty\n");
      return;
   }
   printf("Queue elements: ");
   for (i = front; i <= rear; i++)
   {
      printf("%d ", queue[i]);
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
