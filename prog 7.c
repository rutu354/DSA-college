#include <stdio.h>
#include <ctype.h>

#define MAX 100

double stack[MAX];
int top = -1;

void push(double val)
{
   if (top < MAX - 1)
   {
      stack[++top] = val;
   }
}

double pop()
{
   if (top >= 0)
   {
      return stack[top--];
   }
   return 0;
}

int main()
{
   char exp[MAX];
   int i = 0;
   double op1, op2, res;

   printf("Enter postfix expression: ");
   scanf("%s", exp);

   while (exp[i] != '\0')
   {
      char ch = exp[i];
      if (isdigit(ch))
      {
         push((double)(ch - '0'));
      }
      else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
      {
         op2 = pop();
         op1 = pop();
         switch (ch)
         {
            case '+':
               res = op1 + op2;
               break;
            case '-':
               res = op1 - op2;
               break;
            case '*':
               res = op1 * op2;
               break;
            case '/':
               res = op1 / op2;
               break;
         }
         push(res);
      }
      i++;
   }

   printf("Result: %.2f\n", pop());
   return 0;
}
