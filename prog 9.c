#include <stdio.h>
#define INF 9999999
#define V 20

int main()
{
   int n, cost[V][V], visited[V] = {0};
   int no_of_edges = 0, total_cost = 0;
   int i, j, x, y, min;

   printf("Enter number of vertices: ");
   scanf("%d", &n);

   printf("Enter adjacency matrix:\n");
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         scanf("%d", &cost[i][j]);
         if (cost[i][j] == 0)
         {
            cost[i][j] = INF;
         }
      }
   }

   visited[0] = 1;
   printf("\nEdges in Minimum Spanning Tree:\n");

   while (no_of_edges < n - 1)
   {
      min = INF;
      x = 0;
      y = 0;

      for (i = 0; i < n; i++)
      {
         if (visited[i])
         {
            for (j = 0; j < n; j++)
            {
               if (!visited[j] && cost[i][j])
               {
                  if (min > cost[i][j])
                  {
                     min = cost[i][j];
                     x = i;
                     y = j;
                  }
               }
            }
         }
      }

      printf("%d - %d : %d\n", x, y, cost[x][y]);
      total_cost += cost[x][y];
      visited[y] = 1;
      no_of_edges++;
   }

   printf("Total Cost = %d\n", total_cost);
   return 0;
}
